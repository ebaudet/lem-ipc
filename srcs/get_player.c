/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebaudet <ebaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/01 23:16:27 by ebaudet           #+#    #+#             */
/*   Updated: 2019/11/07 14:53:40 by ebaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "lemipc.h"

t_player	*get_player(void)
{
	static t_player		*p = NULL;

	if (!p)
		p = (t_player *)malloc(sizeof(p));
	return (p);
}
