/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_to.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebaudet <ebaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/01 22:32:10 by ebaudet           #+#    #+#             */
/*   Updated: 2014/06/01 23:56:20 by ebaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "lemipc.h"

void		move_height(t_pos enemy, t_player *player, t_data *data, int t)
{
	int		move;

	move = ((enemy.x - player->pos.x) > 0) ? 1 : -1;
	if (!data->tab[player->pos.x + move][player->pos.y])
	{
		data->tab[player->pos.x + move][player->pos.y] = player->team;
		data->tab[player->pos.x][player->pos.y] = 0;
		player->pos.x += move;
	}
	else
	{
		if (t != 1 && enemy.y != player->pos.y)
			move_width(enemy, player, data, 1);
	}
}

void		move_width(t_pos enemy, t_player *player, t_data *data, int t)
{
	int		move;

	move = ((enemy.y - player->pos.y) > 0) ? 1 : -1;
	if (!data->tab[player->pos.x][player->pos.y + move])
	{
		data->tab[player->pos.x][player->pos.y + move] = player->team;
		data->tab[player->pos.x][player->pos.y] = 0;
		player->pos.y += move;
	}
	else
	{
		if (t != 1 && enemy.y != player->pos.y)
			move_height(enemy, player, data, 1);
	}
}

void		move_to(t_pos enemy, t_player *player, t_data *data)
{
	int		height;
	int		width;

	height = enemy.x - player->pos.x;
	width = enemy.y - player->pos.y;
	if (abs(height) > abs(width))
		move_height(enemy, player, data, 0);
	else
		move_width(enemy, player, data, 0);
}
