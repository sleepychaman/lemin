/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryabicho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 06:24:21 by ryabicho          #+#    #+#             */
/*   Updated: 2017/06/20 06:25:23 by ryabicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "lemin.h"

void	my_putchar(char c)
{
	write(1, &c, 1);
}

void	my_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		my_putchar(str[i]);
		i = i + 1;
	}
}

void	my_putnbr(int nb)
{
	int	mod;

	if (nb < 0)
	{
		nb = nb * -1;
		my_putchar(45);
	}
	if (nb >= 0)
	{
		if (nb >= 10)
		{
			mod = nb % 10;
			nb = nb / 10;
			my_putnbr(nb);
			my_putchar(mod + 48);
		}
		else
			my_putchar(nb + 48);
	}
}

int		my_getnbr(const char *str)
{
	int	i;
	int	nb;

	i = 0;
	nb = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			nb = nb + (str[i] - 48);
			nb = nb * 10;
			i = i + 1;
		}
		else
			return (-1);
	}
	nb = nb / 10;
	return (nb);
}

int		my_strcmp(const char *str, const char *cmp)
{
	int	i;

	i = 0;
	while (cmp[i] != '\0')
	{
		if (cmp[i] != str[i])
			return (1);
		i = i + 1;
	}
	if (str[i] != '\0')
		return (1);
	return (0);
}
