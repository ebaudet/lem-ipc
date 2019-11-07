/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_clear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebaudet <ebaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 14:28:08 by ebaudet           #+#    #+#             */
/*   Updated: 2019/11/07 14:29:14 by ebaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemipc.h"
#include <stdlib.h>

int		return_clear(int code, t_data *shared)
{
	t_player	*p;

	p = get_player();
	shm_clear(p, shared);
	free(p);
	return (code);
}
