/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ipc_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebaudet <ebaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 12:13:06 by ebaudet           #+#    #+#             */
/*   Updated: 2019/11/07 12:40:59 by ebaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemipc.h"
#include <sys/ipc.h>
#include <stdlib.h>

int		ipc_init(t_player **p, t_data **shared)
{
	int		key;

	if ((key = ftok(".", 'A')) == -1)
		return (ft_error("ftok"));
	*p = get_player();
	if (((*p)->id_sh = sh_init(key, shared)) == EXIT_FAILURE)
		return (return_clear(EXIT_FAILURE, *shared));
	if (((*p)->id_sem = semaphore_init(key)) == EXIT_FAILURE)
		return (return_clear(EXIT_FAILURE, *shared));
	if (((*p)->id_msg = msg_init(key)) == EXIT_FAILURE)
		return (return_clear(EXIT_FAILURE, *shared));
	return (EXIT_SUCCESS);
}
