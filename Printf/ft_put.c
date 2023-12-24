/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbonilla <dbonilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 17:14:59 by dbonilla          #+#    #+#             */
/*   Updated: 2022/12/27 01:53:52 by dbonilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_putchar(int c)
{
	write (1, &c, 1);
	return (1);
}

size_t	ft_putstr(char *str)
{
	size_t		i ;

	i = 0;
	if (!str)
		return (write(1, "(null)", 6));
	while ((str[i] != '\0') || (str[i] >= 'a' && str[i] <= 'z') || \
			(str[i] >= 'A' && str[i] <= 'Z'))
	{
		write (1, &str[i], 1);
		i++;
	}
	return (i);
}
