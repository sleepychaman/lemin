/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_values.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryabicho <ryabicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 06:17:03 by ryabicho          #+#    #+#             */
/*   Updated: 2017/07/02 12:30:39 by ryabicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include "utils.h"

t_node			*get_current_node(t_lemin *lemin, const int node,
								const char *name)
{
	t_node		*tmp;

	tmp = lemin->head;
	while (tmp != NULL)
	{
		if (tmp->nb_node == node)
			return (tmp);
		if (name != NULL)
			if (my_strcmp(tmp->name, name) == 0)
				return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

static char		*my_strdup(const char *str)
{
	char		*result;
	int			i;

	i = 0;
	if ((result = malloc(sizeof(char) * my_strlen(str) + 1)) == NULL)
		return (NULL);
	while (str[i])
	{
		result[i] = str[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

static void		check_status(const int status, t_node **current)
{
	if (status == IS_START)
	{
		(*current)->status = IS_START;
		(*current)->distance = MAX_DISTANCE;
	}
	else if (status == IS_END)
	{
		(*current)->status = IS_END;
		(*current)->distance = 0;
	}
	else
	{
		(*current)->status = ROOM;
		(*current)->distance = UNDEFINED;
	}
}

int				fill_node(t_lemin *lemin, char *info, const int status)
{
	static int	node;
	t_node		*current;
	char		**values;

	lemin->parsing++;
	if ((values = my_str_to_wordtab(info, ' ')) == NULL ||
		(current = get_current_node(lemin, node++, NULL)) == NULL ||
		values[0] == NULL || values[1] == NULL || values[2] == NULL)
		return (EXIT_FAILURE);
	check_status(status, &current);
	if ((current->name = my_strdup(values[0])) == NULL ||
		(current->pos.x = my_getnbr(values[1])) == -1 ||
		(current->name[0] == 'L') ||
		(current->pos.y = my_getnbr(values[2])) == -1)
		return (EXIT_FAILURE);
	free_tab(values);
	return (EXIT_SUCCESS);
}

int				fill_link_tab(t_lemin *lemin)
{
	t_node		*node_one;
	t_node		*node_two;
	char		**values;
	int			i;

	i = lemin->parsing;
	while (lemin->map[i] != NULL && i <= lemin->error_line)
	{
		if (lemin->map[i][0] != COMMENT)
		{
			if ((values = my_str_to_wordtab(lemin->map[i], '-')) == NULL)
				return (EXIT_FAILURE);
			if ((node_one = get_current_node(lemin, -1, values[0])) == NULL ||
				(node_two = get_current_node(lemin, -1, values[1])) == NULL)
			{
				lemin->error_line = i;
				return (EXIT_SUCCESS);
			}
			lemin->link[node_one->nb_node][node_two->nb_node] = 1;
			lemin->link[node_two->nb_node][node_one->nb_node] = 1;
			free_tab(values);
		}
		i++;
	}
	return (EXIT_SUCCESS);
}
