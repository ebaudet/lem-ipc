/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemipc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebaudet <ebaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/29 16:34:23 by ebaudet           #+#    #+#             */
/*   Updated: 2014/06/01 17:59:43 by ebaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIPC_H
# define LEMIPC_H

# include <sys/types.h>

# define HEIGHT		12
# define WIDTH		15
# define BUF		1024

typedef struct	s_data
{
	int 		nb_player;
	char		msg[BUF];
	char		tab[HEIGHT][WIDTH];
}				t_data;

typedef struct	s_pos
{
	int			x;
	int			y;
}				t_pos;

int				usage(int ac, char **av);
int				ft_error(char *msg);
void			data_init(key_t key);
int				rand_val();
void			put_player(t_data *data, char team);
void			print_tab(t_data *data);
t_pos			find_enemy(t_data *data, char team, t_pos pos);
int				is_enemy(t_data *data, char team, int x, int y);
int				is_alive(t_data *data, char team, t_pos pos);
void			semaphore(int semid, int sem_op);
int				semaphore_init(key_t key);

#endif
