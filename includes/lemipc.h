/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemipc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebaudet <ebaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/29 16:34:23 by ebaudet           #+#    #+#             */
/*   Updated: 2014/05/30 21:39:41 by ebaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIPC_H
# define LEMIPC_H

# define HEIGHT		50
# define WIDTH		60
# define BUF		1024

typedef struct	s_data
{
	int 		nb_player;
	int			total_ingame;
	char		msg[BUF];
	int			tab[HEIGHT][WIDTH];
}				t_data;

/*
** ft_error.c
*/
int		ft_error(char *msg);

/*
** init_data.c
*/
void	init_data();

#endif
