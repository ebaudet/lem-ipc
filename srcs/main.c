/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebaudet <ebaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/29 16:31:50 by ebaudet           #+#    #+#             */
/*   Updated: 2019/11/07 12:50:01 by ebaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdlib.h>
#include "libft.h"
#include "lemipc.h"

void		loop(t_data *shared, t_player *player, int sem_id)
{
	t_pos	enemy;

	while (shared->nb_player > 0)
	{
		print_tab(shared, player);
		sem_lock(sem_id);
		if (!is_alive(shared, player->team, player->pos))
		{
			shared->nb_player--;
			shared->tab[player->pos.x][player->pos.y] = 0;
			sem_unlock(sem_id);
			return ;
		}
		// enemy = find_enemy(shared, player->team, player->pos);
		enemy = find_closest(shared, player->team, player->pos);
		if (enemy.x != -1)
		{
			move_to(enemy, player, shared);
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
