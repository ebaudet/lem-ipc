/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_alive.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebaudet <ebaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/31 18:09:57 by ebaudet           #+#    #+#             */
/*   Updated: 2019/11/07 14:54:20 by ebaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemipc.h"

int		is_alive(t_data *shared, char team, t_pos pos)
{
	int		enemy;

	enemy = 0;
	if (is_enemy(shared, team, pos.x - 1, pos.y - 1))
		enemy++;
	if (is_enemy(shared, team, pos.x, pos.y - 1))
		enemy++;
	if (is_enemy(shared, team, pos.x + 1, pos.y - 1))
		enemy++;
	if (is_enemy(shared, team, pos.x - 1, pos.y))
		enemy++;
	if (is_enemy(shared, team, pos.x + 1, pos.y))
		enemy++;
	if (is_enemy(shared, team, pos.x - 1, pos.y + 1))
		enemy++;
	if (is_enemy(shared, team, pos.x, pos.y + 1))
		enemy++;
	if (is_enemy(shared, team, pos.x + 1, pos.y + 1))
		enemy++;
	if (enemy > 1)
		return (0);
	return (1);
}
