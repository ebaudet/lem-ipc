/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebaudet <ebaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/31 07:29:44 by ebaudet           #+#    #+#             */
/*   Updated: 2019/10/22 20:30:12 by ebaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemipc.h"

void		player_init(t_data *sh_data, char team, t_player *player)
{
	t_pos	pos;

	while (42)
	{
		pos.x = rand_val() % HEIGHT;
		pos.y = rand_val() % WIDTH;
		if (sh_data->tab[pos.x][pos.y] == 0)
		{
			sh_data->tab[pos.x][pos.y] = team;
			break ;
		}
	}
	player->pos = pos;
	player->team = team;
	player->is_master = 0;
}
