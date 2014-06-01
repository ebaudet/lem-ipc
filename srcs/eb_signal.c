/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eb_signal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebaudet <ebaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/01 23:09:43 by ebaudet           #+#    #+#             */
/*   Updated: 2014/06/01 23:29:13 by ebaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <signal.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include "lemipc.h"
#include "libft.h"

void	eb_sig_action(int s)
{
	key_t		key;
	t_player	*player;
	t_data		*data;
	int			id;
	int			sem_id;

	(void) s;
	player = get_player();
	key = ftok(".",'A');
	id = ipc_init(key, &data);
	sem_id = semaphore_init(key);
	data->tab[player->pos.x][player->pos.y] = 0;
	free(player);
	data->nb_player--;
	shm_clear(id, sem_id, data);
	exit(0);
}

void	get_sig(void)
{
	signal(SIGINT, &eb_sig_action);
}
