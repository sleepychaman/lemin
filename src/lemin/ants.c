/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryabicho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 06:20:28 by ryabicho          #+#    #+#             */
/*   Updated: 2017/07/01 18:20:08 by ryabicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include "utils.h"

static int	check_ants(t_lemin *lemin)
{
	t_ants	*current;

	current = lemin->ants;
	while (current != NULL)
	{
		if (current->room != lemin->end->nb_node)
			return (EXIT_FAILURE);
		current = current->next;
	}
	return (EXIT_SUCCESS);
}

static int	get_fastest_node(int *stack, t_lemin *lemin)
{
	t_node	*current;
	int		fast_node;
	int		min;
	int		i;

	i = 0;
	min = MAX_DISTANCE;
	while (stack[i] != UNDEFINED)
	{
		if ((current = get_current_node(lemin, stack[i], NULL)) == NULL)
			return (EXIT_FAILURE);
		if (current->distance != -1 && current->ant == 0)
			if (min > current->distance)
			{
				min = current->distance;
				fast_node = current->nb_node;
			}
		i++;
	}
	if (min != MAX_DISTANCE)
		return (fast_node);
	return (UNDEFINED);
}

static void	print_ant(t_ants *ant, t_node *current, t_ants *next)
{
	my_putchar('L');
	my_putnbr(ant->ants);
	my_putchar('-');
	my_putstr(current->name);
	if (next != NULL)
		my_putchar(' ');
}

static int	move_this_ant(int *stack, t_ants *ant, t_lemin *lemin)
{
	t_node	*current;
	t_node	*prev;
	int		fast_node;

	if ((prev = get_current_node(lemin, ant->room, NULL)) == NULL)
		return (EXIT_FAILURE);
	if ((fast_node = get_fastest_node(stack, lemin)) != UNDEFINED)
	{
		if ((current = get_current_node(lemin, fast_node, NULL)) == NULL)
			return (EXIT_FAILURE);
		if (prev->nb_node != lemin->start->nb_node)
			prev->ant = 0;
		if (current->nb_node != lemin->end->nb_node)
			current->ant = 1;
		ant->room = fast_node;
		print_ant(ant, current, ant->next);
	}
	free(stack);
	return (EXIT_SUCCESS);
}

int			move_ants(t_lemin *lemin)
{
	t_ants	*current;
	int		*stack;

	my_putchar('\n');
	while (check_ants(lemin) != EXIT_SUCCESS)
	{
		current = lemin->ants;
		while (current != NULL)
		{
			if (current->room != lemin->end->nb_node)
				if ((stack = get_new_stack(current->room, lemin)) == NULL ||
					(move_this_ant(stack, current, lemin) == EXIT_FAILURE))
					return (EXIT_FAILURE);
			current = current->next;
		}
		my_putchar('\n');
	}
	return (EXIT_SUCCESS);
}
