/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 20:13:08 by codespace         #+#    #+#             */
/*   Updated: 2023/11/29 20:17:19 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t ft_putnbr_fd(int nb, int fd)
{
    unsigned int nbr;

    nbr = 0;
    if (nb < 0)
    {
        ft_putchar_fd ('-', fd);
        nbr = (unsigned int)(nb * -1);
    }
    else
        nbr = (unsigned int) nb;
    if (nbr >= 10)
        ft_putnbr_fd(nbr / 10, fd);
    ft_putchar_fd((char)(nbr % 10 + 48), fd);
    return(nbr);
}