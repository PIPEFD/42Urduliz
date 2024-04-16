/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camel_to_snake.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 23:05:10 by codespace         #+#    #+#             */
/*   Updated: 2024/04/16 07:28:17 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

// Función para convertir una cadena de CamelCase a snake_case
void camel_to_snake(char *s)
{
    while (*s) // 🔄 Mientras no se alcance el final de la cadena
    {
        if (*s >= 65 && *s <= 90) // 🤔 Si el carácter actual es una letra mayúscula
        {  
            *s += 32; // 🔄 Convertir la letra mayúscula a minúscula
            write(1, "_", 1); // 🖊️ Escribir un guion bajo antes de la letra convertida
        }
        write(1, &*s, 1); // 🖊️ Escribir el carácter actual en la salida estándar
        s++; // ➡️ Avanzar al siguiente carácter
    }
}

// Función principal
int main(int argc, char **argv)
{
    if (argc == 2) // 🤔 Si se proporciona exactamente un argumento en la línea de comandos
        camel_to_snake(argv[1]); // 🐍 Convertir el argumento de CamelCase a snake_case
    write(1, "\n", 1); // 🖊️ Escribe un salto de línea
    return(0); // Termina el programa
}
