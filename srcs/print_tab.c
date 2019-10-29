/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebaudet <ebaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/31 07:33:57 by ebaudet           #+#    #+#             */
/*   Updated: 2019/10/29 20:00:43 by ebaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lemipc.h"

void	print_tab(t_data *sh_data, t_player *pl)
{
	int		x;
	int		y;

	x = -1;
	while (++x < HEIGHT)
	{
		y = -1;
		while (++y < WIDTH)
		{
			if (pl->pos.x == x && pl->pos.y == y)
				ft_putstr("\033[0;31m");
			if (sh_data->tab[x][y] != 0)
				ft_putchar(sh_data->tab[x][y]);
			else
				ft_putchar('_');
			if (pl->pos.x == x && pl->pos.y == y)
				ft_putstr("\033[0m");
			ft_putchar(' ');
		}
		ft_putchar('\n');
	}
	ft_putstr("il y a ");
	ft_putnbr(sh_data->nb_player);
	ft_putendl(" en jeu.");
}
