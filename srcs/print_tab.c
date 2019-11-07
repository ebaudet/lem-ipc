/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebaudet <ebaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/31 07:33:57 by ebaudet           #+#    #+#             */
/*   Updated: 2019/11/07 14:43:13 by ebaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lemipc.h"

static void		info_tab(t_data *shared, t_player *p)
{
	ft_putstr("il y a ");
	ft_putnbr(shared->nb_player);
	ft_putstr(" en jeu. [");
	ft_putnbr(p->pos.x);
	ft_putstr(";");
	ft_putnbr(p->pos.y);
	ft_putstr("]\n");
}

void			print_tab(t_data *shared, t_player *p)
{
	int		x;
	int		y;

	x = -1;
	while (++x < HEIGHT)
	{
		y = -1;
		while (++y < WIDTH)
		{
			if (p->pos.x == x && p->pos.y == y)
				ft_putstr("\033[0;31m");
			if (shared->tab[x][y] != 0)
				ft_putchar(shared->tab[x][y]);
			else
				ft_putchar('_');
			if (p->pos.x == x && p->pos.y == y)
				ft_putstr("\033[0m");
			ft_putchar(' ');
		}
		ft_putchar('\n');
	}
	info_tab(shared, p);
}
