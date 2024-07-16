/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   snake_to_camel.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 23:15:01 by codespace         #+#    #+#             */
/*   Updated: 2024/07/09 12:26:05 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

// 🔍 Función para convertir una cadena en formato snake_case 🐍 a camelCase
void snake_to_camel(char *s)
{
    int i = 0;

    while (s[i] != '\0')
    {
        if (s[i] == '_')
        {
            i++;
            if (s[i] >= 'a' && s[i] <= 'z')
                s[i] -= 32;
        }
        write(1, &s[i], 1);
        i++;
    }
}

int main(int argc, char **argv)
{
    if (argc == 2)
        snake_to_camel(argv[1]);
    write(1, "\n", 1);
    return 0;
}
