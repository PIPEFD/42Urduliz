/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbonilla <dbonilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 20:03:46 by dbonilla          #+#    #+#             */
/*   Updated: 2022/12/26 21:51:32 by dbonilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check_format(char const *ptr, size_t len, va_list args )
{
	if (*ptr == 'c')
		len += ft_putchar(va_arg(args, int));
	if (*ptr == '%')
		len += ft_putchar('%');
	if (*ptr == 's')
		len += ft_putstr(va_arg(args, char *));
	if (*ptr == 'i' || *ptr == 'd')
		len += ft_putnbr(va_arg(args, int));
	if (*ptr == 'u')
		len += ft_putnbr_usigned(va_arg(args, unsigned int));
	if (*ptr == 'x' || *ptr == 'X' )
		len += ft_puthex(va_arg(args, unsigned int), ptr);
	if (*ptr == 'p')
		len += ft_putstr("0x") + ft_puthex(va_arg(args, unsigned long int),
				ptr);
	return (len);
}

int	ft_printf(char const *str, ...)
{
	va_list	args;
	size_t	len;
	int		i ;

	va_start(args, str);
	len = 0;
	i = 0 ;
	while (str[i])
	{
		if (str[i] != '%')
		{
			write (1, &str[i], 1);
			len++;
		}
		else if (str[i] == '%')
			if (str[i + 1])
				len = ft_check_format(&str[++i], len, args);
		i++;
	}
	return (va_end(args), (int)len);
}
