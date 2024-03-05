/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 14:42:34 by codespace         #+#    #+#             */
/*   Updated: 2023/11/14 02:27:05 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

size_t	ft_putnbr(int nb, int fd)
{
	unsigned int	nbr;

	nbr = 0;
	if (nb == -2147483648)
		return (ft_putstr("-2147483648", fd));
	if (nb < 0)
	{
		ft_putchar ('-', fd);
		nbr = (unsigned int)(nb * -1);
	}
	else
		nbr = (unsigned int)nb;
	if (nbr >= 10)
		ft_putnbr(nbr / 10, fd);
	ft_putchar((char)(nbr % 10 + 48), fd);
	return (nbr);
}
