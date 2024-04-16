/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alpha_mirror.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 23:18:02 by codespace         #+#    #+#             */
/*   Updated: 2024/04/16 07:24:00 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

// Función para reflejar cada letra del alfabeto en su opuesta
void alpha_mirror(char *s)
{
    // 🔄 Itera sobre la cadena hasta encontrar el carácter nulo que indica el final de la cadena
    while (*s)
    {
        // 📌 Si el carácter es una letra mayúscula
        if (*s >= 'A' && *s <= 'Z')
            // 🔄 Calcula el espejo de la letra en mayúscula (por ejemplo, 'A' -> 'Z', 'B' -> 'Y', ...)
            *s = 155 - *s;
        // 📌 Si el carácter es una letra minúscula
        else if (*s >= 'a' && *s <= 'z')
            // 🔄 Calcula el espejo de la letra en minúscula (por ejemplo, 'a' -> 'z', 'b' -> 'y', ...)
            *s =  219 - *s ;
        // ✍️ Escribe el carácter reflejado en la salida estándar
        write(1, &*s, 1);
        s++; // ➡️ Avanza al siguiente carácter en la cadena
    }
}

// Función principal
int main(int argc, char **argv)
{
    // 🔍 Verifica si se proporcionó un argumento al programa
    if (argc == 2)
        // 📌 Llama a la función alpha_mirror con el primer argumento como entrada
        alpha_mirror(argv[1]);
    
    // ✏️ Escribe un salto de línea en la salida estándar
    write(1, "\n", 1);
    return 0;
}
