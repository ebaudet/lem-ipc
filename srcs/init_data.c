/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebaudet <ebaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/30 03:09:36 by ebaudet           #+#    #+#             */
/*   Updated: 2014/05/31 02:35:01 by ebaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lemipc.h"
#include <stdio.h>



#include <stdlib.h>
#include <time.h>

int		put_player(t_data *data)
{
	(void)data;


	srand(time(NULL));
	ft_putnbr(rand());

	
	ft_putchar('\n');
	return (1);
}

int		empty_place(t_data *data, int x, int y)
{
	if (data->tab[x][y] == 0)
	{
		return (1);
	}
	return (0);
}


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
		{
			printf("data[%d][%d] = 0\n", x, y);
			data->tab[x][y] = 0;
		}
	}

	int		i;
	i = -1;
	while (++i < 10)
	{
		put_player(data);
	}
}
