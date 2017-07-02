/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryabicho <ryabicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 06:31:24 by ryabicho          #+#    #+#             */
/*   Updated: 2017/07/02 11:22:22 by ryabicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

/*
** Utils
*/

char		**my_str_to_wordtab(char *x, char y);
char		*my_strcopy(char *y, const char *x);
void		my_putstr(char *x);
void		my_putchar(char x);
void		my_putnbr(int x);
int			my_putstr_error(char *x, int msg);
void		my_putchar_error(char x);
void		my_putnbr_error(int x);
void		print_error(int x);
void		free_tab(char **x);
void		free_link(int **x, int y);
void		set_value(int *x, int *y, int *z, int *a);
int			my_getnbr(const char *x);
int			my_strlen(const char *x);
int			my_strcmp(const char *x, const char *y);

#endif
