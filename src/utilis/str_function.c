/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_function.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryabicho <ryabicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 06:23:51 by ryabicho          #+#    #+#             */
/*   Updated: 2017/07/02 09:30:26 by ryabicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include "utils.h"

int			my_strlen(const char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
		i = i + 1;
	return (i);
}

char		*my_strcopy(char *tmp, const char *str)
{
	int		i;
	int		size;

	size = my_strlen(str);
	i = 0;
	if (!(tmp = malloc(sizeof(char) * (size + 1))))
		return (NULL);
	while (str[i] != '\0')
	{
		tmp[i] = str[i];
		i = i + 1;
	}
	tmp[i] = '\0';
	return (tmp);
}

void		  print_map(char **map, t_lemin *lemin)
{
	int		i;

	i = 0;
	while (map[i] && i < (lemin->error_line))
	{
		my_putstr(map[i]);
		my_putchar('\n');
		/*if (my_strcmp(START, map[i]) == 0)
		{
			my_putchar('\n');
		}
		else if (my_strcmp(END, map[i]) == 0)
		{
			my_putstr(map[i]);
			my_putchar('\n');
		}
		else if (map[i][0] != COMMENT)
		{
			my_putstr(map[i]);
			my_putchar('\n');
		}*/
		i++;
	}
}
