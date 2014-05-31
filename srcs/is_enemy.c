/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_enemy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebaudet <ebaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/31 18:10:42 by ebaudet           #+#    #+#             */
/*   Updated: 2014/05/31 18:11:00 by ebaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemipc.h"

int		is_enemy(t_data *data, char team, int x, int y)
{
	if (x >= HEIGHT || x < 0 || y >= WIDTH || y < 0)
		return (0);
	if (data->tab[x][y] && data->tab[x][y] != team)
		return (1);
	return (0);
}
