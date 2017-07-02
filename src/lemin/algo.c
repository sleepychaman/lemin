/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryabicho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 06:19:31 by ryabicho          #+#    #+#             */
/*   Updated: 2017/06/20 07:57:12 by ryabicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static t_node	*get_edge(t_lemin *lemin, int status)
{
	t_node		*tmp;

	tmp = lemin->head;
	while (tmp != NULL)
	{
		if (tmp->status == status)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

int				*get_new_stack(const int node, t_lemin *lemin)
{
	int			*new_stack;
	int			i;
	int			j;

	if ((new_stack = malloc(sizeof(int) * (lemin->nb_room + 1))) == NULL)
		return (NULL);
	i = 0;
	while (i < lemin->nb_room)
	{
		new_stack[i] = UNDEFINED;
		i++;
	}
	new_stack[i] = UNDEFINED;
	i = 0;
	j = 0;
	while (i < lemin->nb_room)
	{
		if (lemin->link[node][i] != 0)
		{
			new_stack[j] = i;
			j++;
		}
		i++;
	}
	return (new_stack);
}

static int		get_adj_min(int *stack, t_lemin *lemin, t_node *current)
{
	t_node		*adj;
	int			i;
	int			min;

	i = 0;
	min = MAX_DISTANCE;
	while (stack[i] != UNDEFINED)
	{
		if ((adj = get_current_node(lemin, stack[i], NULL)) == NULL)
			return (EXIT_FAILURE);
		if (adj->distance != -1)
			if (min > adj->distance)
				min = adj->distance;
		i++;
	}
	if (current->distance == -1 && min != MAX_DISTANCE)
		current->distance = min + 1;
	free(stack);
	return (EXIT_SUCCESS);
}

static int		is_solvable(t_lemin *lemin)
{
	t_node		*linked;
	int			*stack;
	int			i;

	i = 0;
	if ((stack = get_new_stack(lemin->start->nb_node, lemin)) == NULL)
		return (EXIT_FAILURE);
	while (stack[i] != UNDEFINED)
	{
		if ((linked = get_current_node(lemin, stack[i], NULL)) == NULL)
			return (EXIT_FAILURE);
		if (linked->distance != UNDEFINED)
			return (EXIT_SUCCESS);
		i++;
	}
	free(stack);
	return (EXIT_FAILURE);
}

int				fill_graph(t_lemin *lemin)
{
	int			*stack;
	t_node		*current;
	int			i;

	i = 0;
	if ((lemin->start = get_edge(lemin, IS_START)) == NULL ||
		(lemin->end = get_edge(lemin, IS_END)) == NULL)
		return (EXIT_FAILURE);
	while (i != lemin->nb_room)
	{
		current = lemin->head;
		while (current != NULL)
		{
			if ((stack = get_new_stack(current->nb_node, lemin)) == NULL ||
				(get_adj_min(stack, lemin, current) == EXIT_FAILURE))
				return (EXIT_FAILURE);
			current = current->next;
		}
		i++;
	}
	if (is_solvable(lemin) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
