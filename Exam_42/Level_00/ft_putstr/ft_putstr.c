/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 07:49:17 by codespace         #+#    #+#             */
/*   Updated: 2024/07/09 17:17:49 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_putstr(char *str)
{
    while (*str)
        write(1, &*str++, 1);
}

int main ()
{
    char *str = "Hello, World!";
    ft_putstr(str);
    write(1, "\n", 1);
    return(0);
}   