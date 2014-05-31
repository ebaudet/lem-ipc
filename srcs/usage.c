/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebaudet <ebaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/31 15:52:41 by ebaudet           #+#    #+#             */
/*   Updated: 2014/05/31 15:55:36 by ebaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		usage(int ac, char **av)
{
	if (ac != 2)
	{
		ft_putstr("usage : ");
		ft_putstr(av[0]);
		ft_putendl(" <team>");
		return (0);
	}
	if (ft_strlen(av[1]) != 1)
	{
		ft_putstr("usage : ");
		ft_putstr(av[0]);
		ft_putendl(" <team>\n<team> has to be a char");
		return (0);
	}
	return (1);
}
