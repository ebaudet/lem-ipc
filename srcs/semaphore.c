/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   semaphore.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebaudet <ebaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/01 17:16:25 by ebaudet           #+#    #+#             */
/*   Updated: 2019/11/07 14:44:21 by ebaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/sem.h>
#include <sys/ipc.h>

static int		semaphore(int semid, int sem_op)
{
	struct sembuf		op;

	op.sem_num = 0;
	op.sem_op = sem_op;
	op.sem_flg = 0;
	if (semop(semid, &op, 1) == -1)
		return (-1);
	return (0);
}

int				sem_lock(int semid)
{
	return (semaphore(semid, -1));
}

int				sem_unlock(int semid)
{
	return (semaphore(semid, 1));
}
