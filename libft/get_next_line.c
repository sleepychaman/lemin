/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryabicho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 15:06:29 by ryabicho          #+#    #+#             */
/*   Updated: 2017/02/09 11:36:44 by ryabicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int				get_next_line(int const fd, char **line)
{
	t_data		data;
	static char	*buf[OPEN_MAX];

	if (!line || fd < 0 || !BUFF_SIZE || fd > OPEN_MAX)
		return (-1);
	if (buf[fd] == '\0')
		buf[fd] = ft_strnew(0);
	data.ret = 1;
	while (data.ret > -1)
	{
		if ((data.str = ft_strchr(buf[fd], '\n')) != NULL ||
			((data.str = ft_strchr(buf[fd], '\0')) != NULL && !data.ret))
		{
			*data.str = '\0';
			*line = ft_strdup(buf[fd]);
			ft_memmove(buf[fd], data.str + 1, ft_strlen(data.str + 1) + 1);
			buf[fd] = (!data.ret) ? NULL : buf[fd];
			return (line[0][0] || (!line[0][0] && data.ret > 0));
		}
		if ((data.ret = read(fd, data.tmp, BUFF_SIZE)) == -1)
			return (-1);
		data.tmp[data.ret] = '\0';
		buf[fd] = ft_strjoin_del(buf[fd], data.tmp, 1);
	}
	return (data.ret);
}
