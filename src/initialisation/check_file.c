/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryabicho <ryabicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 03:22:04 by ryabicho          #+#    #+#             */
/*   Updated: 2017/07/02 11:17:36 by ryabicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include "utils.h"

static int	check_room(const char *line)
{
	int		i;

	i = 0;
	while (line[i] != ' ')
	{
		if (line[i] == '\0')
			return (1);
		i = i + 1;
	}
	i = i + 1;
	while (line[i] != ' ')
	{
		if (line[i] < '0' || line[i] > '9')
			return (1);
		i = i + 1;
	}
	i = i + 1;
	while (line[i] != '\0')
	{
		if (line[i] < '0' || line[i] > '9')
			return (1);
		i = i + 1;
	}
	return (0);
}

static int	check_tube(const char *line)
{
	int		i;

	i = 0;
	while (line[i] != '-')
	{
		if (line[i] == '\0' || line[i] == ' ')
			return (1);
		i = i + 1;
	}
	i = i + 1;
	if (line[i] == '\0' || line[i] == ' ')
		return (1);
	while (line[i] != '\0')
	{
		if (line[i] == ' ')
			return (1);
		i = i + 1;
	}
	return (0);
}

static int	check_line(char *file, int tube, t_lemin *lemin)
{
	if (check_room(file) == 0)
	{
		if (tube == 1)
			return (-1);
		lemin->nb_room = lemin->nb_room + 1;
	}
	else if (check_tube(file) == 0)
	{
		if (lemin->nb_room == 0)
			return (-1);
		if (tube == 0)
			tube = 1;
	}
	else
		return (-1);
	return (tube);
}

static int	check_instruction(char *line, char *next_line, t_lemin *lemin)
{
	if (my_strcmp(line, START) == 0 && next_line != NULL)
	{
		lemin->fst = lemin->fst + 1;
		if (lemin->fst != 1)
			return (-1);
	}
	else if (my_strcmp(line, END) == 0 && next_line != NULL)
	{
		lemin->lst = lemin->lst + 1;
		if (lemin->lst != 1)
			return (-1);
	}
	return (0);
}

int			check_file(char **file, t_lemin *lemin)
{
	int		tube;
	int		i;

	i = skip_comment(file);
	tube = 0;
	if (((lemin->total_ants = my_getnbr(file[i++]))) <= 0)
		return (lemin_error(lemin, i - 1));
	while (file[i] != NULL)
	{
		if (file[i][0] != COMMENT)
		{
			if ((tube = check_line(file[i], tube, lemin)) == -1)
				return (lemin_error(lemin, i - 1));
		}
		else
		{
			if ((check_instruction(file[i], file[i + 1], lemin)) == -1)
				return (lemin_error(lemin, i - 1));
		}
		i = i + 1;
	}
	if (lemin->fst != 1 || lemin->lst != 1 || tube != 1 || lemin->nb_room <= 0)
		return (lemin_error(lemin, i - 1));
	lemin->error_line = i;
	return (0);
}
