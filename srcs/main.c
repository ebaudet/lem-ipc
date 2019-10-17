/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebaudet <ebaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/29 16:31:50 by ebaudet           #+#    #+#             */
/*   Updated: 2019/10/17 17:13:00 by ebaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdlib.h>
#include "libft.h"
#include "lemipc.h"

void	loop(t_data *data, t_player *player, int sem_id)
{
	t_pos	enemy;

	while (42)
	{
		print_tab(data);
		semaphore(sem_id, -1);
		if (!is_alive(data, player->team, player->pos))
		{
			data->nb_player--;
			data->tab[player->pos.x][player->pos.y] = 0;
			semaphore(sem_id, 1);
			return ;
		}
		enemy = find_enemy(data, player->team, player->pos);
		if (enemy.x != -1)
		{
			move_to(enemy, player, data);
		}
		semaphore(sem_id, 1);
		sleep(1);
	}
}

int		main(int ac, char **av)
{
	key_t		key;
	int			id;
	t_data		*data;
	int			id_sem;
	t_player	*player;

	get_sig();
	if (!usage(ac, av))
		return (EXIT_SUCCESS);
	if ((key = ftok(".", 'A')) == -1)
		return (ft_error("ftok"));
	if ((id = ipc_init(key, &data)) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if ((id_sem = semaphore_init(key)) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	data->nb_player += 1;
	player = get_player();
	player_init(data, *av[1], player);
	print_tab(data);
	loop(data, player, id_sem);
	shm_clear(id, id_sem, data);
	return (EXIT_SUCCESS);
}
