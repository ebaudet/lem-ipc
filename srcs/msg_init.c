/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebaudet <ebaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 11:43:43 by ebaudet           #+#    #+#             */
/*   Updated: 2019/11/07 12:43:25 by ebaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/shm.h>
#include "libft.h"
#include "lemipc.h"

int		msg_init(key_t key)
{
	int id;

	if ((id = msgget(key, SHM_R | SHM_W)) == -1)
	{
		ft_putstrc("Message Queue already esist\n", C_YELLOW);
		if ((id = msgget(key, IPC_CREAT | SHM_R | SHM_W)) == -1)
			return (ft_error("Error Message Queue"));
	}
	return (id);
}
