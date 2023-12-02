/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 08:09:08 by codespace         #+#    #+#             */
/*   Updated: 2023/11/29 08:15:37 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char    ft_putstr_fd(char *str, int fd)
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