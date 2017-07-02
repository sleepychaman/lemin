# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ryabicho <ryabicho@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/06/13 14:47:43 by ryabicho          #+#    #+#              #
#    Updated: 2017/07/02 14:42:48 by ryabicho         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DIR	= src/

LEMIN	= lemin/

UTILS	= utils/

INIT	= initialisation/

SRC	= $(DIR)main.c \
	  $(DIR)$(INIT)check_map.c \
	  $(DIR)$(INIT)get_values.c \
	  $(DIR)$(INIT)initialisation.c \
	  $(DIR)$(INIT)check_file.c \
	  $(DIR)$(INIT)check_file_tools.c \
	  $(DIR)$(INIT)check_map_data.c \
	  $(DIR)$(UTILS)free_handler.c \
	  $(DIR)$(UTILS)tools.c \
	  $(DIR)$(UTILS)str_function.c \
	  $(DIR)$(UTILS)my_str_to_wordtab.c \
	  $(DIR)$(UTILS)print_error.c \
	  $(DIR)$(LEMIN)init_ants.c \
	  $(DIR)$(LEMIN)algo.c \
	  $(DIR)$(LEMIN)ants.c

NAME	= lem-in

OBJS	= $(SRC:.c=.o)

CFLAGS	+= -Wall -Wextra -Werror

CFLAGS	+= -I include/

LIBFT = -L ./libft/ -lft

RM	= rm -f

CC	= gcc

all:	$(NAME)

$(NAME): $(OBJS)
	make -C ./libft/
	$(CC) -o $(NAME) $(OBJS) $(LIBFT)

clean:
	make -C ./libft clean
	$(RM) $(OBJS)

fclean:	clean
	make -C ./libft fclean
	$(RM) $(NAME)

re: fclean all

.PHONY:	all clean fclean re
