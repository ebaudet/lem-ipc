/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebaudet <ebaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/31 07:29:44 by ebaudet           #+#    #+#             */
/*   Updated: 2019/11/04 13:22:25 by ebaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemipc.h"

static t_pos	get_initial_pos(t_data *shared)
{
	t_pos	pos;

	// pos.x = rand_val() % HEIGHT;
	// pos.y = rand_val() % WIDTH;
	pos.y = 9;
	pos.x = shared->nb_player;
	return (pos);
}

void		player_init(t_data *shared, char team, t_player *player)
{
	t_pos	pos;

	while (42)
	{
		pos = get_initial_pos(shared);
		// pos.x = rand_val() % HEIGHT;
		// pos.y = rand_val() % WIDTH;
		if (shared->tab[pos.x][pos.y] == 0)
		{
			shared->tab[pos.x][pos.y] = team;
			break ;
		}
	}
	player->pos = pos;
	player->team = team;
	player->is_master = 0;
}
