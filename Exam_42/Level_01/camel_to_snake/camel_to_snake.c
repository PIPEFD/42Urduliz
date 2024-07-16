/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camel_to_snake.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 23:05:10 by codespace         #+#    #+#             */
/*   Updated: 2024/07/09 12:00:53 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

// 🔍 Función para convertir una cadena de CamelCase a snake_case 🐍

void camel_to_snake(char *s)
{
    while (*s)
    {
        if (*s >= 65 && *s <= 90) 
        {  
            *s += 32; 
            write(1, "_", 1); 
        }
        write(1, &*s, 1); 
        s++; 
    }
}

int main(int argc, char **argv)
{
    if (argc == 2) 
        camel_to_snake(argv[1]);
    write(1, "\n", 1);
    return(0);
}
