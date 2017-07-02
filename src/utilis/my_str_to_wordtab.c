/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_str_to_wordtab.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryabicho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 06:22:27 by ryabicho          #+#    #+#             */
/*   Updated: 2017/06/20 07:58:43 by ryabicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	count_line(char *str, char delim)
{
	int		l;
	int		i;

	l = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] != delim && str[i] != '\t' && str[i])
		{
			i++;
			if (str[i] == delim || str[i] == '\t' || str[i] == '\0')
				l++;
		}
		while ((str[i] == delim || str[i] == '\t') && str[i])
			i++;
	}
	return (l + 1);
}

static char	**fill_tab(char **tab, char *str, char delim)
{
	int		i[3];

	i[0] = 0;
	i[1] = 0;
	i[2] = 0;
	while (str[i[0]])
	{
		i[2] = 0;
		while (str[i[0]] != delim && str[i[0]] != '\t' && str[i[0]])
		{
			tab[i[1]][i[2]] = str[i[0]];
			i[0]++;
			i[2]++;
			if (str[i[0]] == delim || str[i[0]] == '\t' || str[i[0]] == '\0')
			{
				tab[i[1]][i[2]] = 0;
				i[1]++;
			}
		}
		while ((str[i[0]] == delim || str[i[0]] == '\t') && str[i[0]])
			i[0]++;
	}
	tab[i[1]] = 0;
	return (tab);
}

static int	malloc_line(int i[3], char **tab, char *str, char delim)
{
	while (str[i[0]] != delim && str[i[0]] != '\t' && str[i[0]])
	{
		i[0]++;
		i[2]++;
		if (str[i[0]] == delim || str[i[0]] == '\t' || str[i[0]] == '\0')
		{
			if ((tab[i[1]] = malloc(sizeof(char) * i[2] + 1)) == NULL)
				return (EXIT_FAILURE);
			i[1]++;
		}
	}
	return (EXIT_SUCCESS);
}

char		**my_str_to_wordtab(char *str, char delim)
{
	char	**tab;
	int		i[3];

	i[1] = 0;
	i[0] = 0;
	if (str == NULL ||
		(tab = malloc(sizeof(char *) * count_line(str, delim))) == NULL)
		return (NULL);
	while (str[i[0]])
	{
		i[2] = 0;
		if (malloc_line(i, tab, str, delim) == EXIT_FAILURE)
			return (NULL);
		while ((str[i[0]] == delim || str[i[0]] == '\t') && str[i[0]])
			i[0]++;
	}
	return (fill_tab(tab, str, delim));
}
