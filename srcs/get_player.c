/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebaudet <ebaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/01 23:16:27 by ebaudet           #+#    #+#             */
/*   Updated: 2014/06/01 23:18:19 by ebaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "lemipc.h"

t_player	*get_player(void)
{
	static t_player		*player = NULL;

	if (!player)
		player = (t_player  *)malloc(sizeof(player));
	return (player);
}
