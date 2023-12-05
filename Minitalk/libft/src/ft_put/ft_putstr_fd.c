/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 08:09:08 by codespace         #+#    #+#             */
/*   Updated: 2023/12/03 15:12:24 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

size_t    ft_putstr_fd(char *str, int fd)
{
    int i;

    i = 0;
    
    while (str + i && str[i])
    {
        ft_putchar_fd(str[i], fd);
        i++;
    }
    return (0);
}