/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_enemy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebaudet <ebaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/31 17:47:43 by ebaudet           #+#    #+#             */
/*   Updated: 2014/05/31 17:48:07 by ebaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "lemipc.h"

t_pos		find_enemy(t_data *data, char team, t_pos pos)
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
			if (data->tab[tmp.y][tmp.x] && data->tab[tmp.y][tmp.x] != team)
			{
				if (find.x == -1 || ((abs(pos.x - find.x)
					+ abs(pos.y - find.y)) > (abs(pos.x - tmp.x)
					+ abs(pos.y - tmp.y))))
				{
					find.x = tmp.x;
					find.y = tmp.y;
				}
			}
		}
	}
	return (find);
}
