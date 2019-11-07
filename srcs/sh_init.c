/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebaudet <ebaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/01 19:17:14 by ebaudet           #+#    #+#             */
/*   Updated: 2019/11/07 12:11:46 by ebaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/ipc.h>
#include <sys/shm.h>
#include "lemipc.h"
#include "libft.h"

int		sh_init(key_t key, t_data **shared)
{
	int		id;

	if ((id = shmget(key, sizeof(t_data), IPC_CREAT | IPC_EXCL | 0666)) == -1)
	{
		ft_putstrc("shared_msg already exist\n", C_YELLOW);
		if ((id = shmget(key, sizeof(t_data), 0)) == -1)
			return (ft_error("Error shmget"));
		*shared = (t_data *)shmat(id, NULL, SHM_R | SHM_W);
	}
	else
	{
		*shared = (t_data *)shmat(id, NULL, SHM_R | SHM_W);
		data_init(*shared);
	}
	return (id);
}
