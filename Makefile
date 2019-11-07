# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebaudet <ebaudet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/05/27 14:12:54 by ebaudet           #+#    #+#              #
#    Updated: 2019/11/07 15:08:18 by ebaudet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= lemipc
FILES	= main.c ft_error.c data_init.c rand_val.c player_init.c print_tab.c \
		usage.c find_enemy.c is_alive.c is_enemy.c semaphore.c \
		semaphore_init.c sh_init.c shm_clear.c move_to.c eb_signal.c \
		get_player.c clear_all.c set_pos.c ipc_init.c msg_init.c return_clear.c
SRCS	= $(addprefix srcs/, $(FILES))
OBJS	= $(SRCS:srcs/%.c=.obj/%.o)
INC		= -I includes -I libft/includes
FLAGS	= -Wall -Wextra -Werror
LIB		= -L libft -lft
CC		= gcc

all: $(NAME)

$(NAME): make_libft $(OBJS)
	@echo ""
	$(CC) $(FLAGS) $(SRCS) -o $(NAME) $(INC) $(INC) $(LIB)
	@echo "> Compilation \033[35m$(NAME)\033[m [\033[32mDONE\033[m]\n"

.obj/%.o: srcs/%.c
	@mkdir -p .obj
	@$(CC) -c $< -o $@ $(FLAGS) $(INC)
	@echo -n .

gdb: make_libft
	cc -g $(FLAGS) $(SRCS) -o $(NAME) $(INC) $(INC) $(LIB)
	gdb $(NAME)

clean:
	rm -rf .obj
	make -C libft clean

fclean: clean
	rm -f $(NAME)
	make -C libft fclean

re: fclean all

make_libft:
	@echo "Compilation de la \033[35mlibft\033[m :"
	@make -C libft
	@echo ""

.PHONY: all gdb clean fclean re make_libft
