/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shm_clear.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebaudet <ebaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/01 22:17:05 by ebaudet           #+#    #+#             */
/*   Updated: 2019/11/07 12:25:44 by ebaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/shm.h>
#include <sys/sem.h>
#include <sys/msg.h>
#include <stdlib.h>
#include "lemipc.h"

int		shm_clear(t_player *p, t_data *shared)
{
	int		result;

	result = EXIT_SUCCESS;
	if (shared->nb_player < 1)
	{
		if (shmctl(p->id_sh, IPC_RMID, NULL) == EXIT_FAILURE)
			result = EXIT_FAILURE;
		if (semctl(p->id_sem, 0, IPC_RMID, 0) == EXIT_FAILURE)
			result = EXIT_FAILURE;
		if (msgctl(p->id_msg, IPC_RMID, NULL) == EXIT_FAILURE)
			result = EXIT_FAILURE;
	}
	return (result);
}
