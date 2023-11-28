/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbonilla <dbonilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 17:09:39 by dbonilla          #+#    #+#             */
/*   Updated: 2022/12/27 01:51:36 by dbonilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned long int num, char const *str)
{
	int	len;

	len = 0 ;
	if (*str >= 32 || *str <= 122)
	{
		if (*str == 'x' || *str == 'p')
		{
			if (num >= 16)
				len += ft_puthex (num / 16, str);
			len += ft_putchar (HEXX[num % 16]);
		}
		if (*str == 'X')
		{
			if (num >= 16)
				len += ft_puthex(num / 16, str);
			len += ft_putchar (HEX[num % 16]);
		}
	}
	else
	{
		return (0);
	}
	return (len);
}
