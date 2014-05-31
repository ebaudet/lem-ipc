/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebaudet <ebaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/29 16:31:50 by ebaudet           #+#    #+#             */
/*   Updated: 2014/05/31 07:36:05 by ebaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdlib.h>
#include "libft.h"
#include "lemipc.h"

int		usage(int ac, char **av)
{
	if (ac != 2)
	{
		ft_putstr("usage : ");
		ft_putstr(av[0]);
		ft_putendl(" <team>");
		return (0);
	}
	return (1);
}

void	loop(t_data *data, int id)
{
	char	*line;

	while (get_next_line(0, &line) > 0)
	{
		if (!ft_strcmp(line, "p"))
			ft_putendl(data->msg);
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
			ft_strcpy(data->msg, line);
		}
	}
}

int		main(int ac, char **av)
{
	key_t		key;
	int			id;
	t_data		*data;

	if (!usage(ac, av))
		return (EXIT_FAILURE);
	if ((key = ftok(".",'A')) == -1)
		return (ft_error("ftok"));
	if ((id = shmget(key, sizeof(t_data), IPC_CREAT | IPC_EXCL | 0666)) == -1)
	{
		ft_putendl("shared_msg already exist");
		id = shmget(key, sizeof(t_data), 0);
		data = (t_data *)shmat(id, NULL, SHM_R | SHM_W);
	}
	else
	{
		data = (t_data *)shmat(id, NULL, SHM_R | SHM_W);
		init_data(data);
	}
	print_tab(data);
	loop(data, id);
	return (EXIT_SUCCESS);
}
