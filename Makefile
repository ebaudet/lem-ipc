# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebaudet <ebaudet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/05/27 14:12:54 by ebaudet           #+#    #+#              #
#    Updated: 2019/11/04 13:22:36 by ebaudet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= lemipc
FILES	= main.c ft_error.c data_init.c rand_val.c player_init.c print_tab.c \
		usage.c find_enemy.c is_alive.c is_enemy.c semaphore.c \
		semaphore_init.c ipc_init.c shm_clear.c move_to.c eb_signal.c \
		get_player.c clear_all.c set_pos.c
SRCS	= $(addprefix srcs/, $(FILES))
OBJS	= $(SRCS:srcs/%.c=.obj/%.o)
INC		= -I includes -I libft/includes
FLAGS	= -Wall -Wextra -Werror
LIB		= -L libft -lft
CC		= gcc

all: $(NAME)

$(NAME): $(OBJS)
	make -C libft
	$(CC) $(FLAGS) $(SRCS) -o $(NAME) $(INC) $(INC) $(LIB)

.obj/%.o: srcs/%.c
	mkdir -p .obj
	$(CC) -c $< -o $@ $(FLAGS) $(INC)

gdb:
	make -C libft
	cc -g $(FLAGS) $(SRCS) -o $(NAME) $(INC) $(INC) $(LIB)
	gdb $(NAME)

clean:
	rm -rf .obj

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all gdb clean fclean re
