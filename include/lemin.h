/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryabicho <ryabicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 06:26:01 by ryabicho          #+#    #+#             */
/*   Updated: 2017/07/02 11:17:38 by ryabicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include <stdlib.h>

# define ROOM 0
# define IS_END 1
# define IS_START 2

# define START "##start"
# define END "##end"
# define COMMENT '#'

# define MAX_DISTANCE 2147483647
# define UNDEFINED -1

/*
** Position
*/

typedef struct		s_pos
{
	int				x;
	int				y;
}					t_pos;

/*
** Structure pour les maillons des fourmis
*/

typedef struct		s_ants
{
	int				ants;
	int				room;
	struct s_ants	*next;
	struct s_ants	*prev;
}					t_ants;

/*
** Structure pour les maillons du graph
*/

typedef struct		s_node
{
	char			*name;
	int				ant;
	int				nb_node;
	int				status;
	int				distance;
	t_pos			pos;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

/*
** Structure Principale
*/

typedef struct		s_lemin
{
	t_node			*head;
	t_node			*start;
	t_node			*end;
	t_ants			*ants;
	char			**map;
	int				**path;
	int				**link;
	int				total_ants;
	int				error_line;
	int				fst;
	int				lst;
	int				nb_room;
	int				parsing;
}					t_lemin;

/*
** Initialisation
*/

t_node				*get_current_node(t_lemin *x, const int y, const char *z);
int					check_map(t_lemin *x);
int					check_file(char **x, t_lemin *y);
int					initialisation(t_lemin *x);
int					fill_node(t_lemin *x, char *y, const int z);
int					fill_link_tab(t_lemin *x);
int					skip_comment(char **x);
int					lemin_error(t_lemin *x, int y);
int					check_map_data(t_lemin *x);

/*
** Algo
*/

int					fill_graph(t_lemin *x);
int					*get_new_stack(const int x, t_lemin *y);

/*
** move_ants
*/

int					init_ants_list(t_lemin *x);
int					move_ants(t_lemin *y);
int					get_path(t_lemin *x);

/*
** Utils
*/

void				free_node(t_node *x);
void				free_list(t_ants *x);
void				print_map(char **x, t_lemin *y);

#endif
