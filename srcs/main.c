/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebaudet <ebaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/29 16:31:50 by ebaudet           #+#    #+#             */
/*   Updated: 2014/06/01 22:18:49 by ebaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdlib.h>
#include "libft.h"
#include "lemipc.h"

void	loop(t_data *data, t_player *player, int id, int id_sem)
{
	char	*line;

	(void) player;
	(void) id_sem;
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
	int			id_sem;
	t_player	player;

	if (!usage(ac, av))
		return (EXIT_FAILURE);
	if ((key = ftok(".",'A')) == -1)
		return (ft_error("ftok"));
	if ((id = ipc_init(key, &data)) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if ((id_sem = semaphore_init(key)) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	data->nb_player += 1;
	player_init(data, *av[1], &player);
	print_tab(data);
	loop(data, &player, id, id_sem);
	return (EXIT_SUCCESS);
}
