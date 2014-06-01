/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ipc_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebaudet <ebaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/01 19:17:14 by ebaudet           #+#    #+#             */
/*   Updated: 2014/06/01 19:30:55 by ebaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/ipc.h>
#include <sys/shm.h>
#include "lemipc.h"
#include "libft.h"

int		ipc_init(key_t key, t_data **data)
{
	int		id;

	if ((id = shmget(key, sizeof(t_data), IPC_CREAT | IPC_EXCL | 0666)) == -1)
	{
		ft_putendl("shared_msg already exist");
		if ((id = shmget(key, sizeof(t_data), 0)) == -1)
			return (ft_error("Error shmget"));
		*data = (t_data *)shmat(id, NULL, SHM_R | SHM_W);
	}
	else
	{
		*data = (t_data *)shmat(id, NULL, SHM_R | SHM_W);
		data_init(*data);
	}
	return (id);
}
