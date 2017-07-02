/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryabicho <ryabicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/19 14:15:05 by ryabicho          #+#    #+#             */
/*   Updated: 2017/07/02 11:21:38 by ryabicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <stdio.h>
#include "lemin.h"
#include "utils.h"

int		main(void)
{
	t_lemin	*lemin;

	if ((lemin = malloc(sizeof(*lemin))) == NULL ||
		(check_map(lemin) == EXIT_FAILURE) ||
		(initialisation(lemin) == EXIT_FAILURE) ||
		(fill_graph(lemin) == EXIT_FAILURE) ||
		(init_ants_list(lemin) == EXIT_FAILURE) ||
		(move_ants(lemin) == EXIT_FAILURE))
		return (my_putstr_error("ERROR\n", EXIT_FAILURE));
	free_tab(lemin->map);
	free_link(lemin->link, lemin->nb_room);
	free_node(lemin->head);
	free_list(lemin->ants);
	free(lemin);
	return (EXIT_SUCCESS);
}
