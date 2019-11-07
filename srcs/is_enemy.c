/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_enemy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebaudet <ebaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/31 18:10:42 by ebaudet           #+#    #+#             */
/*   Updated: 2019/11/07 14:54:37 by ebaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemipc.h"

int		is_enemy(t_data *shared, char team, int x, int y)
{
	if (x >= HEIGHT || x < 0 || y >= WIDTH || y < 0)
		return (0);
	if (shared->tab[x][y] && shared->tab[x][y] != team)
		return (1);
	return (0);
}
