/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shm_clear.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebaudet <ebaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/01 22:17:05 by ebaudet           #+#    #+#             */
/*   Updated: 2014/06/01 22:19:47 by ebaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/shm.h>
#include <sys/sem.h>
#include <stdlib.h>

void	shm_clear(int id, int semid)
{
	shmctl(id, IPC_RMID, NULL);	
	semctl(semid, 0, IPC_RMID, 0);
}
