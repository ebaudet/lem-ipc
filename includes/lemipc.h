/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemipc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebaudet <ebaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/29 16:34:23 by ebaudet           #+#    #+#             */
/*   Updated: 2014/05/31 16:02:54 by ebaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIPC_H
# define LEMIPC_H

# define HEIGHT		12
# define WIDTH		15
# define BUF		1024

typedef struct	s_data
{
	int 		nb_player;
	char		msg[BUF];
	char		tab[HEIGHT][WIDTH];
}				t_data;

/*
** usage.c
*/
int		usage(int ac, char **av);

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
void	put_player(t_data *data, char team);

/*
** print_tab.c
*/
void	print_tab(t_data *data);


#endif
