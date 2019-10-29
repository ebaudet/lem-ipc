/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_all.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebaudet <ebaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 17:21:06 by ebaudet           #+#    #+#             */
/*   Updated: 2019/10/25 17:42:43 by ebaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemipc.h"
#include "libft.h"

int		clear_all(char team, t_data *sh_data, int id, int id_sem)
{
	if (team != '%')
		return (0);
	sh_data->nb_player = 0;
	shm_clear(id, id_sem, sh_data);
	ft_putstrc("All ipcs cleared\n", C_GREEN);
	return (1);
}
