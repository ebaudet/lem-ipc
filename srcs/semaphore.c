/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   semaphore.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebaudet <ebaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/01 17:16:25 by ebaudet           #+#    #+#             */
/*   Updated: 2014/06/01 17:22:43 by ebaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <sys/types.h>
#include <sys/sem.h>
#include <sys/ipc.h>

void	semaphore(int semid, int sem_op)
{
	struct sembuf		op;

	op.sem_num = 0;
	op.sem_op = sem_op;
	op.sem_flg = IPC_NOWAIT;
	semop(semid, &op, 1);
}
