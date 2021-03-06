/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eb_signal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebaudet <ebaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/01 23:09:43 by ebaudet           #+#    #+#             */
/*   Updated: 2019/11/07 14:39:06 by ebaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <signal.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include "lemipc.h"
#include "libft.h"

void	eb_sig_action(int s)
{
	t_player	*p;
	t_data		*shared;

	(void)s;
	if (ipc_init(&p, &shared) == EXIT_FAILURE)
		exit(0);
	shared->tab[p->pos.x][p->pos.y] = 0;
	shared->nb_player--;
	shm_clear(p, shared);
	free(p);
	exit(0);
}

void	get_sig(void)
{
	signal(SIGINT, &eb_sig_action);
	signal(SIGQUIT, &eb_sig_action);
	signal(SIGTERM, &eb_sig_action);
	signal(SIGCHLD, &eb_sig_action);
}
