/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebaudet <ebaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/29 16:31:50 by ebaudet           #+#    #+#             */
/*   Updated: 2019/11/04 13:03:07 by ebaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdlib.h>
#include "libft.h"
#include "lemipc.h"

void	loop(t_data *sh_data, t_player *player, int sem_id)
{
	t_pos	enemy;

	while (sh_data->nb_player > 0)
	{
		print_tab(sh_data, player);
		sem_lock(sem_id);
		if (!is_alive(sh_data, player->team, player->pos))
		{
			sh_data->nb_player--;
			sh_data->tab[player->pos.x][player->pos.y] = 0;
			sem_unlock(sem_id);
			return ;
		}
		// enemy = find_enemy(sh_data, player->team, player->pos);
		enemy = find_closest(sh_data, player->team, player->pos);
		if (enemy.x != -1)
		{
			move_to(enemy, player, sh_data);
		}
		sem_unlock(sem_id);
		sleep(1);
	}
}

int		main(int ac, char **av)
{
	key_t		key;
	int			id;
	t_data		*sh_data;
	int			id_sem;
	t_player	*player;

	get_sig();
	if (!usage(ac, av))
		return (EXIT_SUCCESS);
	if ((key = ftok(".", 'A')) == -1)
		return (ft_error("ftok"));
	if ((id = ipc_init(key, &sh_data)) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if ((id_sem = semaphore_init(key)) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (clear_all(*av[1], sh_data, id, id_sem))
		return (EXIT_SUCCESS);
	sh_data->nb_player += 1;
	player = get_player();
	player_init(sh_data, *av[1], player);
	print_tab(sh_data, player);
	loop(sh_data, player, id_sem);
	shm_clear(id, id_sem, sh_data);
	return (EXIT_SUCCESS);
}
