/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebaudet <ebaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/29 16:31:50 by ebaudet           #+#    #+#             */
/*   Updated: 2014/06/01 19:30:44 by ebaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdlib.h>
#include "libft.h"
#include "lemipc.h"

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
	if ((id = ipc_init(key, &data)) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	data->nb_player += 1;
	put_player(data, *av[1]);
	print_tab(data);
	loop(data, id);
	return (EXIT_SUCCESS);
}


/*#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>*/

/*
int main(int argc, char **argv)
{
	key_t clef;
	int semid;
	sembuf op;

	clef = ftok(argv[0], ID_PROJET); //Obtention d'un clé
	semid = semget(clef, 1, IPC_CREAT | IPC_EXCL | 0666);
	//Obtention d'un identifiant de sémaphore
	semctl(semid, 0, SET_VAL, 1); //Initialisation du sémapore à 1
	 
	op.sem_num = O; //Numéro de notre sémaphore: le premier et le seul
	op.sem_op = -1; //Pour un P() on décrémente
	op.sem_flg = 0; //On ne s'en occupe pas

	semop(semid, &op, 1); //Entrée dans la section critique (P() ou down())
	//Section critique
	op.sem_op = 1; //Pour un V() on incrémente
	semop(semid, &op, 1); //Sortie de la section critique (V() ou up())

	semctl(semid, 0, IPC_RMID, 0); //Destruction du sémaphore

	return 0;
}
*/
