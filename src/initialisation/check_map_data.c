/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryabicho <ryabicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 06:16:17 by ryabicho          #+#    #+#             */
/*   Updated: 2017/07/01 20:37:07 by ryabicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include "utils.h"

static int	my_strcmp_custumize(const char *str, const char *cmp, char c)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != cmp[i])
			return (1);
		i = i + 1;
	}
	if (cmp[i] != c)
		return (1);
	return (0);
}

static int	find_line_error(t_node *check, t_lemin *lemin, int nb)
{
	int		i;

	i = 0;
	while (lemin->map[i] != NULL)
	{
		if (my_strcmp_custumize(check->name, lemin->map[i], ' ') == 0)
		{
			nb = nb - 1;
			if (nb == 0)
			{
				lemin->error_line = i;
				return (1);
			}
		}
		i = i + 1;
	}
	return (1);
}

int			check_map_data(t_lemin *lemin)
{
	t_node	*check;

	while (lemin->head->next != NULL)
	{
		check = lemin->head->next;
		while (check->next != NULL)
		{
			if (my_strcmp(check->name, lemin->head->name) == 0)
				return (find_line_error(check, lemin, 2));
			else if ((check->pos.x == lemin->head->pos.x)
					&& (check->pos.y == lemin->head->pos.y))
				return (find_line_error(check, lemin, 1));
			check = check->next;
		}
		lemin->head = lemin->head->next;
	}
	while (lemin->head->prev != NULL)
		lemin->head = lemin->head->prev;
	return (0);
}
