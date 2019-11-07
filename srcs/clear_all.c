/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_all.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebaudet <ebaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 17:21:06 by ebaudet           #+#    #+#             */
/*   Updated: 2019/11/07 12:47:06 by ebaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemipc.h"
#include "libft.h"

int		clear_all(char team, t_data *shared)
{
	if (team != '%')
		return (0);
	shared->nb_player = 0;
	ft_putstrc("All ipcs cleared\n", C_GREEN);
	return (1);
}
