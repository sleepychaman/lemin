/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_del.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryabicho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 11:22:45 by ryabicho          #+#    #+#             */
/*   Updated: 2017/02/09 11:35:41 by ryabicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin_del(char *s1, char *s2, int index)
{
	char	*tmp;
	char	*tmp2;
	char	*str;

	tmp = s1;
	tmp2 = s2;
	str = ft_strjoin(tmp, tmp2);
	if (index == 1)
		ft_strdel(&s1);
	else if (index == 2)
		ft_strdel(&s2);
	else
	{
		ft_strdel(&s1);
		ft_strdel(&s2);
	}
	return (str);
}
