/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebaudet <ebaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/31 07:29:44 by ebaudet           #+#    #+#             */
/*   Updated: 2019/11/07 09:32:26 by ebaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemipc.h"

static t_pos	get_initial_pos(t_data *shared, int i)
{
	t_pos	pos;

	// pos.x = rand_val() % HEIGHT;
	// pos.y = rand_val() % WIDTH;
	pos.x = 9;
	pos.y = shared->nb_player + i;
	return (pos);
}

void		player_init(t_data *shared, char team, t_player *player)
{
	t_pos	pos;
	int		i;

	i = 0;
	while (42)
	{
		pos = get_initial_pos(shared, i);
		// pos.x = rand_val() % HEIGHT;
		// pos.y = rand_val() % WIDTH;
		if (shared->tab[pos.x][pos.y] == 0)
		{
			shared->tab[pos.x][pos.y] = team;
			break ;
		}
		i++;
	}
	player->pos = pos;
	player->team = team;
	player->is_master = 0;
}
