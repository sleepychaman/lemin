/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryabicho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 06:21:12 by ryabicho          #+#    #+#             */
/*   Updated: 2017/06/20 08:00:15 by ryabicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static t_ants	*add_elem(int num, t_lemin *lemin)
{
	t_ants		*elem;

	if (!(elem = malloc(sizeof(*elem))))
		return (NULL);
	elem->ants = num;
	elem->room = (lemin->start)->nb_node;
	elem->next = NULL;
	return (elem);
}

int				init_ants_list(t_lemin *lemin)
{
	int			count;
	t_ants		*tmp;
	t_ants		*elem;

	count = 1;
	if ((lemin->ants = add_elem(count, lemin)) == NULL)
		return (EXIT_FAILURE);
	tmp = lemin->ants;
	count = count + 1;
	while (count <= lemin->total_ants)
	{
		if ((elem = add_elem(count, lemin)) == NULL)
			return (EXIT_FAILURE);
		while (tmp->next != NULL)
			tmp = tmp->next;
		elem->prev = tmp;
		tmp->next = elem;
		count = count + 1;
	}
	lemin->ants->prev = NULL;
	if (count != 1)
		elem->next = NULL;
	return (EXIT_SUCCESS);
}
