/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebaudet <ebaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/30 03:09:36 by ebaudet           #+#    #+#             */
/*   Updated: 2014/06/01 19:19:31 by ebaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lemipc.h"
#include <stdio.h>

void	data_init(t_data *data)
{
	int		x;
	int		y;

	x = -1;
	while (++x < HEIGHT)
	{
		y = -1;
		while (++y < WIDTH)
			data->tab[x][y] = 0;
	}
	data->nb_player = 0;
}
