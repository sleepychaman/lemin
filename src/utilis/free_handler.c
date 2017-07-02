/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryabicho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 06:21:39 by ryabicho          #+#    #+#             */
/*   Updated: 2017/06/20 06:22:17 by ryabicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void		free_tab(char **file)
{
	int		i;

	i = 0;
	if (file == NULL)
		return ;
	while (file[i] != NULL)
	{
		free(file[i]);
		i = i + 1;
	}
	free(file);
}

void		free_link(int **tab, int size)
{
	int		i;

	i = 0;
	while (i < size)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void		free_node(t_node *head)
{
	t_node	*tmp;
	t_node	*tmp1;

	if (head == NULL)
		return ;
	if (head->next == NULL)
	{
		free(head->name);
		free(head);
		return ;
	}
	tmp = head->next;
	while (tmp != NULL)
	{
		tmp1 = tmp;
		tmp = tmp->next;
		free(tmp1->name);
		free(tmp1);
	}
	free(head->name);
	free(head);
}

void		free_list(t_ants *ant)
{
	t_ants	*tmp;
	t_ants	*tmp1;

	if (ant == NULL)
		return ;
	if (ant->next == NULL)
	{
		free(ant);
		return ;
	}
	tmp = ant->next;
	while (tmp != NULL)
	{
		tmp1 = tmp;
		tmp = tmp->next;
		free(tmp1);
	}
	free(ant);
}
