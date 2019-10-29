/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebaudet <ebaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 17:33:20 by ebaudet           #+#    #+#             */
/*   Updated: 2019/10/25 17:35:49 by ebaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstrc(char const *s, int color)
{
	ft_putstr("\033[0;");
	ft_putnbr(color);
	ft_putstr("m");
	ft_putstr(s);
	ft_putstr("\033[0m");
}
