/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file_tools.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryabicho <ryabicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 06:15:05 by ryabicho          #+#    #+#             */
/*   Updated: 2017/07/02 11:17:39 by ryabicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int	lemin_error(t_lemin *lemin, int i)
{
	lemin->error_line = i + 1;
	return (-1);
}

int	skip_comment(char **file)
{
	int	i;

	i = 0;
	while (file[i][0] == COMMENT)
		i = i + 1;
	return (i);
}
