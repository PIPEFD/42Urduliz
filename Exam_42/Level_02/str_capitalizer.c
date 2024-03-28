/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_capitalizer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 23:16:54 by codespace         #+#    #+#             */
/*   Updated: 2024/03/28 23:16:55 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

// Función para convertir las letras de una cadena a mayúsculas o minúsculas alternadamente
void str_capitalizer(char *s)
{
    int i = 0;

    // 🔄 Itera sobre la cadena hasta llegar al final
    while (s[i])
    {
        // 🔍 Ignora los espacios o tabulaciones al principio de la cadena
        while (s[i] != '\0' && (s[i] == ' ' || s[i] == '\t'))
        {
            write(1, s, 1);
            ++s;
        }

        // 🔄 Convierte la letra siguiente a mayúscula si es minúscula
        if (s[i] != '\0')
        {
            if (s[i] >= 'a' && s[i] <= 'z')
                s[i] = s[i] - ('a' - 'A');
            write(1, s, 1);
            ++s;
        }

        // 🔄 Convierte la letra siguiente a minúscula si es mayúscula
        while (s[i] != '\0' && s[i] != ' ' && s[i] != '\t')
        { 
            if (s[i] >= 'A' && s[i] <= 'Z')
                s[i] = s[i] + ('a' - 'A');
            write(1, s, 1);
            ++s; 
        }
    }
}

int main(int argc, char **argv)
{
    // 🧠 Si no se proporcionan argumentos, imprime un salto de línea
    if (argc == 1)
        write(1, "\n", 1);
    else
    {
        int i = 1;
        // 🔄 Itera sobre los argumentos (cadenas) proporcionados
        while (i < argc)
        {
            str_capitalizer(argv[i]); // 🧠 Llama a la función para convertir la cadena
            write(1, "\n", 1); // 🖨️ Imprime un salto de línea después de cada cadena procesada
            i++;
        }
    }
    return 0;
}
