/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebaudet <ebaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/30 03:11:30 by ebaudet           #+#    #+#             */
/*   Updated: 2019/10/25 17:45:12 by ebaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "lemipc.h"

int		ft_error(char *msg)
{
	ft_putstrc(msg, C_RED);
	ft_putchar('\n');
	return (EXIT_FAILURE);
}
