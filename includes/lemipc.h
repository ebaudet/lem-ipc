/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemipc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebaudet <ebaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/29 16:34:23 by ebaudet           #+#    #+#             */
/*   Updated: 2019/11/07 12:47:21 by ebaudet          ###   ########.fr       */
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
	int			id_sh;
	int			id_sem;
	int			id_msg;
}				t_player;

typedef struct s_msg
{

}				t_msg;

int				usage(int ac, char **av);
int				ft_error(char *msg);
int				ipc_init(t_player**p, t_data **shared);
int				sh_init(key_t key, t_data **data);
int				semaphore_init(key_t key);
int				msg_init(key_t key);
void			data_init(t_data *data);
int				rand_val();
void			player_init(t_data *data, char team, t_player *player);
void			print_tab(t_data *data, t_player *pl);
t_pos			find_enemy(t_data *data, char team, t_pos pos);
t_pos			find_closest(t_data *shd, char team, t_pos p);
int				is_enemy(t_data *data, char team, int x, int y);
int				is_alive(t_data *data, char team, t_pos pos);
int				sem_lock(int semid);
int				sem_unlock(int semid);
int				shm_clear(t_player *p, t_data *shared);
void			move_to(t_pos enemy, t_player *player, t_data *data);
t_player		*get_player(void);
void			move_height(t_pos enemy, t_player *player, t_data *data
	, int t);
void			move_width(t_pos enemy, t_player *player, t_data *data
	, int t);
void			get_sig(void);
void			eb_sig_action(int s);
int				clear_all(char team, t_data *shared);
t_pos			set_pos(int x, int y);
int				return_clear(int code, t_data *shared);

#endif
