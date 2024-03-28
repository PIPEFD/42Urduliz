/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   snake_to_camel.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 23:15:01 by codespace         #+#    #+#             */
/*   Updated: 2024/03/28 23:15:04 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

// Función para convertir una cadena en formato snake_case a camelCase
void snake_to_camel(char *s)
{
    int i = 0;

    while (s[i] != '\0')
    {
        // 🐍 Si encuentra un guion bajo, convierte el siguiente carácter a mayúscula
        if (s[i] == '_')
        {
            i++;
            // 🛠️ Se asume que el carácter siguiente es una letra minúscula
            if (s[i] >= 'a' && s[i] <= 'z')
                s[i] -= 32; // 📈 Convierte a mayúscula restando 32 a su valor ASCII
        }
        // ✍️ Imprime el carácter actual
        write(1, &s[i], 1);
        i++;
    }
}

int main(int argc, char **argv)
{
    if (argc == 2)
        snake_to_camel(argv[1]); // 🧠 Llama a la función snake_to_camel con el argumento pasado
    write(1, "\n", 1); // 📝 Imprime un salto de línea al final
    return 0;
}
