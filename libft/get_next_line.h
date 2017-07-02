/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryabicho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 15:13:24 by ryabicho          #+#    #+#             */
/*   Updated: 2017/02/09 11:37:18 by ryabicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <limits.h>

# define BUFF_SIZE 3

typedef struct	s_data
{
	char		tmp[BUFF_SIZE + 1];
	char		*str;
	int			ret;
}				t_data;

void			ft_strdel(char **as);
size_t			ft_strlen(const char *s);
int				get_next_line(int const fd, char **line);
char			*ft_strnew(size_t size);
char			*ft_strchr(const char *s, int c);
char			*ft_strdup(const char *s1);
void			*ft_memmove(void *s1, const void *s2, size_t n);
char			*ft_strjoin_del(char *s1, char *s2, int index);

#endif
