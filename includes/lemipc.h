/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemipc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebaudet <ebaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/29 16:34:23 by ebaudet           #+#    #+#             */
/*   Updated: 2014/05/31 07:35:31 by ebaudet          ###   ########.fr       */
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

/*
** rand_val.c
*/
int		rand_val();

/*
** put_player.c
*/
void	put_player(t_data *data, int player);

/*
** print_tab.c
*/
void	print_tab(t_data *data);


#endif
