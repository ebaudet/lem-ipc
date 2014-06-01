/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebaudet <ebaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/31 07:29:44 by ebaudet           #+#    #+#             */
/*   Updated: 2014/06/01 19:42:04 by ebaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemipc.h"

t_pos		put_player(t_data *data, char team)
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
	return (pos);
}
