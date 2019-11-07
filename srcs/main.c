/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebaudet <ebaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/29 16:31:50 by ebaudet           #+#    #+#             */
/*   Updated: 2019/11/07 13:27:54 by ebaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <sys/msg.h>
#include <stdlib.h>
#include "libft.h"
#include "lemipc.h"

void		loop(t_data *shared, t_player *p, int sem_id)
{
	t_pos	enemy;
	t_msg	msg;

	while (shared->nb_player > 0)
	{
		sem_lock(sem_id);
		print_tab(shared, p);
		if (!is_alive(shared, p->team, p->pos))
		{
			shared->nb_player--;
			shared->tab[p->pos.x][p->pos.y] = 0;
			sem_unlock(sem_id);
			return ;
		}
		if (msgrcv(p->id_msg, &msg, sizeof(msg.pos), p->team, IPC_NOWAIT) == -1) {
			ft_putstrc("No message for team\n", C_CYAN);
			enemy = find_closest(shared, p->team, p->pos);
		} else {
			ft_putstrc("Message for team. Enemy on [", C_CYAN);
			ft_putnbr(msg.pos.x);
			ft_putstrc(";", C_CYAN);
			ft_putnbr(msg.pos.y);
			ft_putstrc("]\n", C_CYAN);
			enemy = find_closest(shared, p->team, msg.pos);
		}
		// enemy = find_enemy(shared, p->team, p->pos);

		if (enemy.x != -1)
		{
			move_to(enemy, p, shared);
			msg.pos = set_pos(enemy.x, enemy.y);
			msg.msg_type = p->team;
			msgsnd(p->id_msg, &msg, sizeof(msg.pos), 0);
		}
		sem_unlock(sem_id);
		sleep(1);
	}
}

int		return_clear(int code, t_data *shared)
{
	t_player	*p;

	p = get_player();
	shm_clear(p, shared);
	free(p);
	return (code);
}

int			main(int ac, char **av)
{
	t_data		*shared;
	t_player	*p;

	get_sig();
	if (!usage(ac, av))
		return (EXIT_SUCCESS);
	if (ipc_init(&p, &shared) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (clear_all(*av[1], shared))
		return (return_clear(EXIT_SUCCESS, shared));
	shared->nb_player += 1;
	player_init(shared, *av[1], p);
	print_tab(shared, p);
	loop(shared, p, p->id_sem);
	return (return_clear(EXIT_SUCCESS, shared));
}
