/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_capitalizer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 23:16:54 by codespace         #+#    #+#             */
/*   Updated: 2024/04/01 15:11:42 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

// 🔠 Función para capitalizar la última letra de cada palabra en una cadena
void str_capitalizer(char *str)
{
    int i = 0;

    while (str[i]) // 🔁 Recorre la cadena
    {
        if (str[i] >= 'A' && str[i] <= 'Z') // 🔠 Convierte letras mayúsculas a minúsculas
            str[i] += 32;
        if ((str[i] >= 'a' && str[i] <= 'z') && (str[i - 1] == ' ' || str[i - 1] == '\t' || str[i + 1] == '\0'))
            str[i] -= 32; // 🔠 Capitaliza la última letra de cada palabra
        write(1, &str[i++], 1); // 🔠 Escribe cada carácter en stdout
    }
}

int main()
{
    char str[] = "hello world!";

    rstr_capitalizer(str); // 🔠 Aplica la función a la cadena
    write(1, "\n", 1); // 🔠 Imprime un salto de línea al final
    return 0;
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
