/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryabicho <ryabicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 06:23:14 by ryabicho          #+#    #+#             */
/*   Updated: 2017/07/02 11:23:10 by ryabicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "lemin.h"

void	my_putchar_error(char c)
{
	write(2, &c, 1);
}

int		my_putstr_error(char *str, int msg)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		my_putchar_error(str[i]);
		i = i + 1;
	}
	return (msg);
}

void	my_putnbr_error(int nb)
{
	int	mod;

	if (nb < 0)
	{
		nb = nb * -1;
		my_putchar_error(45);
	}
	if (nb >= 0)
	{
		if (nb >= 10)
		{
			mod = nb % 10;
			nb = nb / 10;
			my_putnbr_error(nb);
			my_putchar_error(mod + 48);
		}
		else
			my_putchar_error(nb + 48);
	}
}

void	print_error(int line)
{
	my_putstr_error("Error syntax at line ", 1);
	my_putnbr_error(line);
	my_putchar_error('\n');
}
