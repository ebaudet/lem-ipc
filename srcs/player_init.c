/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebaudet <ebaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/31 07:29:44 by ebaudet           #+#    #+#             */
/*   Updated: 2014/06/01 19:49:56 by ebaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemipc.h"

void		player_init(t_data *data, char team, t_player *player)
{
	t_pos	pos;

	while (42)
	{
		pos.x = rand_val() % HEIGHT;
		pos.y = rand_val() % WIDTH;
		if (data->tab[pos.x][pos.y] == 0)
		{
			data->tab[pos.x][pos.y] = team;
			break ;
		}
	}
	player->pos = pos;
	player->team = team;
	player->is_master = 0;
}
