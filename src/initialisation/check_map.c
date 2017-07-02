/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryabicho <ryabicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 14:37:19 by ryabicho          #+#    #+#             */
/*   Updated: 2017/07/02 11:37:24 by ryabicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "../libft/libft.h"
#include "utils.h"
#include "lemin.h"

static char	**my_realloc_file(char **file, int size)
{
	char	**tmp;
	int		i;

	if (!(tmp = malloc(sizeof(char *) * size + 1)))
		return (NULL);
	i = 0;
	while (file[i] != NULL)
	{
		tmp[i] = my_strcopy(tmp[i], file[i]);
		i = i + 1;
	}
	tmp[i] = NULL;
	free_tab(file);
	return (tmp);
}

char		*get_room_name(char *line)
{
	int		i;
	char	*name;

	i = 0;
	while (line[i] != ' ')
		i = i + 1;
	if (!(name = malloc(sizeof(char) * i)))
		return (NULL);
	i = 0;
	while (line[i] != ' ')
	{
		name[i] = line[i];
		i = i + 1;
	}
	return (name);
}

int			check_map(t_lemin *lemin)
{
	char	**file;
	int		i;
	int		j;

	i = 0;
	if (!(file = malloc(sizeof(char *) * (i + 2))))
		return (1);
	get_next_line(0, &file[i]);
	while (file[i] != NULL && j != 0)
	{
		i = i + 1;
		file[i] = NULL;
		file = my_realloc_file(file, (i + 1));
		j = get_next_line(0, &file[i]);
	}
	file[i] = NULL;
	lemin->nb_room = 0;
	lemin->fst = 0;
	lemin->lst = 0;
	lemin->map = file;
	if ((check_file(file, lemin)) < 0)
	{
		print_map(lemin->map, lemin);
		return (1);
	}
	return (0);
}
