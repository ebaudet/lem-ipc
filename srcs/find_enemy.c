/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_enemy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebaudet <ebaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/31 17:47:43 by ebaudet           #+#    #+#             */
/*   Updated: 2019/11/07 13:31:04 by ebaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "lemipc.h"

t_pos		find_enemy(t_data *shdata, char team, t_pos pos)
{
	t_pos	tmp;
	t_pos	find;

	find.x = -1;
	find.y = -1;
	tmp.x = -1;
	while (++tmp.x < HEIGHT)
	{
		tmp.y = -1;
		while (++tmp.y < WIDTH)
		{
			if (shdata->tab[tmp.y][tmp.x] && shdata->tab[tmp.y][tmp.x] != team)
			{
				if (find.x == -1 || ((abs(pos.x - find.x)
					+ abs(pos.y - find.y)) > (abs(pos.x - tmp.x)
					+ abs(pos.y - tmp.y))))
				{
					find.x = tmp.x;
					find.y = tmp.y;
					return (find);
				}
			}
		}
	}
	return (find);
}

static int		test_pos(t_data *shd, t_pos pos, char team)
{
	if (pos.x < 0 || pos.x >= HEIGHT)
		return (0);
	else if (pos.y < 0 || pos.y >= WIDTH)
		return (0);
	else if (!shd->tab[pos.x][pos.y])
		return (0);
	else if (shd->tab[pos.x][pos.y] == team)
		return (0);
	return (1);
}

static t_pos	find_dist(t_data *shd, t_pos p, int dist, char team)
{
	int		n;
	t_pos	find;
	n = -1;
	while (++n < dist)
	{
		find = set_pos(p.x - (dist - n), p.y - n);
		if (test_pos(shd, find, team))
			return (find);
		find = set_pos(p.x + n, p.y - (dist - n));
		if (test_pos(shd, find, team))
			return (find);
		find = set_pos(p.x + (dist - n), p.y + n);
		if (test_pos(shd, find, team))
			return (find);
		find = set_pos(p.x - n, p.y + (dist - n));
		if (test_pos(shd, find, team))
			return (find);
	}
	find = set_pos(-1, -1);
	return (find);
}

static int		get_max_dist(t_pos pos)
{
	int 	max;
	int		tmp;

	max = abs(0 - pos.x) + abs(0 - pos.y);
	tmp = abs(HEIGHT - 1 - pos.x) + abs(0 - pos.y);
	max = tmp > max ? tmp : max;
	tmp = abs(pos.x) + abs(WIDTH - 1 - pos.y);
	max = tmp > max ? tmp : max;
	tmp = abs(HEIGHT - 1 - pos.x) + abs(WIDTH - 1 - pos.y);
	max = tmp > max ? tmp : max;
	return (max);
}

t_pos	find_closest(t_data *shd, char team, t_pos p)
{
	int		dist_max;
	int		dist;
	t_pos	find;

	if (test_pos(shd, p, team))
		return (p);
	dist = 0;
	dist_max = get_max_dist(p);
	while (++dist <= dist_max)
	{
		find = find_dist(shd, p, dist, team);
		if (find.x != -1 && find.y != -1)
			return (find);
	}
	find = set_pos(-1, -1);
	return (find);
}


/*
	[p.x - dist][p.y]
		[p.x - (dist - n)][p.y - n]
		[p.x - (dist - 0)][p.y - 0]
		[p.x - (dist - 1)][p.y - 1]
		[p.x - (dist - 2)][p.y - 2]
		[p.x - (dist - 3)][p.y - 3]
	[p.x][p.y - dist]
		[p.x + n][p.y - (dist - n)]
		[p.x + 0][p.y - (dist - 0)]
		[p.x + 1][p.y - (dist - 1)]
		[p.x + 2][p.y - (dist - 2)]
		[p.x + 3][p.y - (dist - 3)]
	[p.x + dist][p.y]
		[p.x + (dist - n)][p.y + n]
		[p.x + (dist - 0)][p.y + 0]
		[p.x + (dist - 1)][p.y + 1]
		[p.x + (dist - 2)][p.y + 2]
		[p.x + (dist - 3)][p.y + 3]
	[p.x][p.y + dist]
		[p.x - n][p.y + (dist - n)]
		[p.x - 0][p.y + (dist - 0)]
		[p.x - 1][p.y + (dist - 1)]
		[p.x - 2][p.y + (dist - 2)]
		[p.x - 3][p.y + (dist - 3)]
*/

