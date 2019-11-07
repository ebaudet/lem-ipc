/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_to.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebaudet <ebaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/01 22:32:10 by ebaudet           #+#    #+#             */
/*   Updated: 2019/11/04 16:07:32 by ebaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "lemipc.h"


void	move_pos(t_data *shared, t_player *p, t_pos new_pos)
{
	shared->tab[new_pos.x][new_pos.y] = p->team;
	shared->tab[p->pos.x][p->pos.y] = 0;
	p->pos = new_pos;
}

char	get_tab_pos(t_data *shared, t_pos pos)
{
	return (shared->tab[pos.x][pos.y]);
}

void		move_height(t_pos enemy, t_player *p, t_data *shared, int t)
{
	int		move;
	t_pos	new_pos;

	move = ((enemy.x - p->pos.x) > 0) ? 1 : -1;
	if (t == 2)
		move = -move;
	if ((p->pos.x + move) > HEIGHT)
		move = -move;
	else if ((p->pos.x + move) < 0)
		move = -move;
	new_pos = set_pos(p->pos.x + move, p->pos.y);
	if (get_tab_pos(shared, new_pos) == 0)
		move_pos(shared, p, new_pos);
	else if (get_tab_pos(shared, new_pos) == p->team)
		move_width(enemy, p, shared, 2);
	else
	{
		if (t == 0)
		{
			if (enemy.y != p->pos.y)
				move_width(enemy, p, shared, 1);
		}
	}
}

void		move_width(t_pos enemy, t_player *p, t_data *shared, int t)
{
	int		move;
	t_pos	new_pos;

	move = ((enemy.y - p->pos.y) > 0) ? 1 : -1;
	if (t == 2)
		move = -move;
	if ((p->pos.y + move) > WIDTH)
		move = -move;
	else if ((p->pos.y + move) < 0)
		move = -move;
	new_pos = set_pos(p->pos.x, p->pos.y + move);
	if (get_tab_pos(shared, new_pos) == 0)
		move_pos(shared, p, new_pos);
	else if (get_tab_pos(shared, new_pos) == p->team)
		move_height(enemy, p, shared, 2);
	else
	{
		if (t == 0)
		{
			if (enemy.y != p->pos.y)
				move_height(enemy, p, shared, 1);
		}
	}
}

void		move_to(t_pos enemy, t_player *p, t_data *shared)
{
	int		height;
	int		width;

	height = enemy.x - p->pos.x;
	width = enemy.y - p->pos.y;
	if (abs(height) > abs(width))
		move_height(enemy, p, shared, 0);
	else
		move_width(enemy, p, shared, 0);
}
