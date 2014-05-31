/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebaudet <ebaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/31 07:33:57 by ebaudet           #+#    #+#             */
/*   Updated: 2014/05/31 07:42:45 by ebaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lemipc.h"

void	print_tab(t_data *data)
{
	int		x;
	int		y;

	x = -1;
	while (++x < HEIGHT)
	{
		y = -1;
		while (++y < WIDTH)
		{
			if (data->tab[x][y] != 0)
				ft_putnbr(data->tab[x][y]);
			else
				ft_putchar('_');
			ft_putchar(' ');
		}
		ft_putchar('\n');
	}
}
