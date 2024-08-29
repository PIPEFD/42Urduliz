/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 17:33:22 by codespace         #+#    #+#             */
/*   Updated: 2024/08/28 12:49:31 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

//
void repeat_alpha(char *s)
{
    int repeat;

    while (*s)
    {
        repeat = 1;
        if ((*s >= 'a' && *s <= 'z'))
            repeat += *s - 'a';
        else if (*s >= 'A' && *s <= 'Z')
            repeat += *s - 'A';
        while (repeat)
        {
            write(1, &*s, 1);
            repeat--;
        }
        s++;
    }
}

// Función principal
int main(int argc, char **argv)
{
    // 🔍 Verifica si se proporcionó un argumento al programa
    if (argc == 2)
        // 📌 Llama a la función repeat_alpha con el primer argumento como entrada
        repeat_alpha(argv[1]);

    // ✏️ Escribe un salto de línea en la salida estándar
    write(1, "\n", 1);
    return (0);
}
