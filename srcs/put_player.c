/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebaudet <ebaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/31 07:29:44 by ebaudet           #+#    #+#             */
/*   Updated: 2014/05/31 15:51:11 by ebaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemipc.h"

void		put_player(t_data *data, char team)
{
	int		x;
	int		y;

	while (42)
	{
		x = rand_val() % HEIGHT;
		y = rand_val() % WIDTH;
		if (data->tab[x][y] == 0)
		{
			data->tab[x][y] = team;
			break ;
		}
	}
}
