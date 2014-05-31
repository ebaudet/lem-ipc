/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebaudet <ebaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/30 03:09:36 by ebaudet           #+#    #+#             */
/*   Updated: 2014/05/31 07:37:20 by ebaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lemipc.h"
#include <stdio.h>

void	init_data(t_data *data)
{
	ft_putendl("création du tableau");

	int		x;
	int		y;

	x = -1;
	while (++x < HEIGHT)
	{
		y = -1;
		while (++y < WIDTH)
			data->tab[x][y] = 0;
	}

	int		i;
	i = -1;
	while (++i < 10)
	{
		put_player(data, i);
	}
}
