/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebaudet <ebaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/29 16:31:50 by ebaudet           #+#    #+#             */
/*   Updated: 2014/05/30 03:14:12 by ebaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdlib.h>
#include "libft.h"
#include "lemipc.h"


void	loop(char *shared_msg, int id)
{
	char	*line;

	while (get_next_line(0, &line) > 0)
	{
		if (!ft_strcmp(line, "p"))
			ft_putendl(shared_msg);
		else if (!ft_strcmp(line, "exit"))
			return ;
		else if (!ft_strcmp(line, "clear"))
		{
			if (shmctl(id, IPC_RMID, NULL) == -1)
			{
				ft_error("shmctl(remove)");
				return ;
			}
		}
		else
		{
			ft_strcpy(shared_msg, line);
		}
	}
}

int		main(int ac, char **av)
{
	key_t	key;
	int		id;
	char	*shared_msg;

	(void)ac;
	(void)av;
	if ((key = ftok(".",'A')) == -1)
		return (ft_error("ftok"));
	if ((id = shmget(key, sizeof(shared_msg), IPC_CREAT | IPC_EXCL | 0666)) == -1)
	{
		ft_putendl("shared_msg already exist");
		id = shmget(key, sizeof(shared_msg), 0);
	}
	else
		init_data();
	shared_msg = (char *)shmat(id, NULL, SHM_R | SHM_W);
	loop(shared_msg, id);
	return (EXIT_SUCCESS);
}
