/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbonilla <dbonilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 17:13:34 by dbonilla          #+#    #+#             */
/*   Updated: 2022/12/26 21:01:14 by dbonilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_usigned(unsigned int n)
{
	int	len;

	len = 0;
	if (n > 9)
		len += ft_putnbr_usigned(n / 10);
	len += ft_putchar((n % 10) + 48);
	return (len);
}

int	ft_putnbr(int nb)
{
	int	n;

	n = 0;
	if (nb >= '0' || nb <= '9')
	{
		if (nb == -2147483648)
		{
			return (ft_putstr ("-2147483648"));
		}
		else if (0 > nb)
		{
			nb *= -1;
			n = ft_putchar('-');
		}
		if (nb > 9)
		{
			n += ft_putnbr(nb / 10);
		}
		n += ft_putchar((nb % 10) + 48);
	}
	else
	{
		return (0);
	}	
	return (n);
}
