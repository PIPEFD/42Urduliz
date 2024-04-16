/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 07:49:17 by codespace         #+#    #+#             */
/*   Updated: 2024/04/16 07:50:31 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_putstr(char *str) // 🔄 Itera sobre la cadena hasta encontrar el carácter nulo que indica el final de la cadena
{
    while (*str) // 🔄 Mientras no se alcance el final de la cadena
        write(1, &*str++, 1); // ✍️ Escribe el carácter actual en la salida estándar y avanza al siguiente carácter
}

int main ()
{
    char *str = "Hello, World!";
    ft_putstr(str);
    write(1, "\n", 1);
    return(0);
}   