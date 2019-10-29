/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemipc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebaudet <ebaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/29 16:34:23 by ebaudet           #+#    #+#             */
/*   Updated: 2019/10/29 18:53:28 by ebaudet          ###   ########.fr       */
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
	int			nb_player;
	char		msg[BUF];
	char		tab[HEIGHT][WIDTH];
}				t_data;

typedef struct	s_pos
{
	int			x;
	int			y;
}				t_pos;

typedef struct	s_player
{
	t_pos		pos;
	char		team;
	char		is_master;
}				t_player;

int				usage(int ac, char **av);
int				ft_error(char *msg);
int				ipc_init(key_t key, t_data **data);
int				semaphore_init(key_t key);
void			data_init(t_data *data);
int				rand_val();
void			player_init(t_data *data, char team, t_player *player);
void			print_tab(t_data *data, t_player *pl);
t_pos			find_enemy(t_data *data, char team, t_pos pos);
t_pos			find_closest(t_data *shd, char team, t_pos p);
int				is_enemy(t_data *data, char team, int x, int y);
int				is_alive(t_data *data, char team, t_pos pos);
void			semaphore(int semid, int sem_op);
void			shm_clear(int id, int semid, t_data *data);
void			move_to(t_pos enemy, t_player *player, t_data *data);
t_player		*get_player(void);
void			move_height(t_pos enemy, t_player *player, t_data *data
	, int t);
void			move_width(t_pos enemy, t_player *player, t_data *data
	, int t);
void			get_sig(void);
void			eb_sig_action(int s);
int				clear_all(char team, t_data *sh_data, int id, int id_sem);

#endif
