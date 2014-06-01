/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebaudet <ebaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/29 16:31:50 by ebaudet           #+#    #+#             */
/*   Updated: 2014/06/01 23:06:55 by ebaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdlib.h>
#include "libft.h"
#include "lemipc.h"

void	loop(t_data *data, t_player *player, int id, int sem_id)
{
	char	*line;
	t_pos	enemy;

	while (42)
	{
		print_tab(data);
		if (!is_alive(data, player->team, player->pos))
		{
			data->nb_player--;
			data->tab[player->pos.x][player->pos.y] = 0;
			return ;
		}
		semaphore(sem_id, -1);
		enemy = find_enemy(data, player->team, player->pos);
		if (enemy.x != -1)
		{
			move_to(enemy, player, data);
		}
		sleep(1);
		semaphore(sem_id, 1);
	}
}

int		main(int ac, char **av)
{
	key_t		key;
	int			id;
	t_data		*data;
	int			id_sem;
	t_player	player;

	if (!usage(ac, av))
		return (EXIT_FAILURE);
	if ((key = ftok(".",'A')) == -1)
		return (ft_error("ftok"));
	if ((id = ipc_init(key, &data)) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if ((id_sem = semaphore_init(key)) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	data->nb_player += 1;
	player_init(data, *av[1], &player);
	print_tab(data);
	loop(data, &player, id, id_sem);
	shm_clear(id, id_sem, data);
	return (EXIT_SUCCESS);
}
