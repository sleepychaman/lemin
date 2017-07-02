/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryabicho <ryabicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 06:18:08 by ryabicho          #+#    #+#             */
/*   Updated: 2017/07/02 11:17:35 by ryabicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include "utils.h"

static int		fill_lemin(t_lemin *lemin)
{
	int			i;

	i = skip_comment(lemin->map) + 1;
	lemin->parsing = 0;
	while (lemin->map[i] != NULL && lemin->parsing < lemin->nb_room
		&& i <= lemin->error_line)
	{
		if (my_strcmp(START, lemin->map[i]) == 0)
		{
			if (fill_node(lemin, lemin->map[++i], IS_START) == EXIT_FAILURE)
				return (EXIT_FAILURE);
		}
		else if (my_strcmp(END, lemin->map[i]) == 0)
		{
			if (fill_node(lemin, lemin->map[++i], IS_END) == EXIT_FAILURE)
				return (EXIT_FAILURE);
		}
		else if (lemin->map[i][0] != COMMENT)
			if (fill_node(lemin, lemin->map[i], ROOM) == EXIT_FAILURE)
				return (EXIT_FAILURE);
		++i;
	}
	lemin->parsing = i;
	return (EXIT_SUCCESS);
}

static t_node	*create_elem(int nb_node)
{
	t_node		*elem;

	if ((elem = malloc(sizeof(*elem))) == NULL)
		return (NULL);
	elem->nb_node = nb_node;
	elem->ant = 0;
	elem->next = NULL;
	return (elem);
}

static t_node	*init_list(t_lemin *lemin)
{
	t_node		*head;
	t_node		*elem;
	t_node		*tmp;
	int			i;

	i = 0;
	if ((head = create_elem(i)) == NULL)
		return (NULL);
	tmp = head;
	while (++i < lemin->nb_room)
	{
		if ((elem = create_elem(i)) == NULL)
			return (NULL);
		while (tmp->next != NULL)
			tmp = tmp->next;
		elem->prev = tmp;
		tmp->next = elem;
	}
	head->prev = NULL;
	if (i != 1)
		elem->next = NULL;
	return (head);
}

static int		init_link_tab(t_lemin *lemin)
{
	int			i;
	int			j;

	i = 0;
	if ((lemin->link = malloc(sizeof(int *) * lemin->nb_room)) == NULL)
		return (EXIT_FAILURE);
	while (i < lemin->nb_room)
	{
		j = -1;
		if ((lemin->link[i] = malloc(sizeof(int) * lemin->nb_room)) == NULL)
			return (EXIT_FAILURE);
		while (++j < lemin->nb_room)
			lemin->link[i][j] = 0;
		i++;
	}
	return (EXIT_SUCCESS);
}

int				initialisation(t_lemin *lemin)
{
	if ((init_link_tab(lemin) == EXIT_FAILURE) ||
		((lemin->head = init_list(lemin)) == NULL) ||
		(fill_lemin(lemin) == EXIT_FAILURE) ||
		(fill_link_tab(lemin) == EXIT_FAILURE))
		return (EXIT_FAILURE);
	if (check_map_data(lemin) == 1)
	{
		print_map(lemin->map, lemin);
		return (EXIT_FAILURE);
	}
	else
		print_map(lemin->map, lemin);
	return (EXIT_SUCCESS);
}
