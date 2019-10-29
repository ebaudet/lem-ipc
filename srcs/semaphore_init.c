/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   semaphore_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebaudet <ebaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/01 17:16:03 by ebaudet           #+#    #+#             */
/*   Updated: 2019/10/25 17:45:50 by ebaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include "libft.h"
#include "lemipc.h"

int		semaphore_init(key_t key)
{
	int		semid;

	if ((semid = semget(key, 1, IPC_CREAT | IPC_EXCL | 0666)) == -1)
	{
		ft_putstrc("semaphore already exist\n", C_YELLOW);
		if ((semid = semget(key, 1, 0)) == -1)
		{
			return (ft_error("cannot get semaphore"));
		}
	}
	semctl(semid, 0, SETVAL, 1);
	return (semid);
}
