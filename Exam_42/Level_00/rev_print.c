/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 12:06:33 by codespace         #+#    #+#             */
/*   Updated: 2024/04/01 12:06:34 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

// 🔁 Función para imprimir una cadena al revés en stdout
void rev_print(char *str)
{
    int i = 0;
    while (str[i] != '\0') // 🔁 Encuentra el final de la cadena
    {
        i++;
    }
    while (str[--i]) // 🖨️🔁 Imprime los caracteres en orden inverso
        write(1, &str[i], 1); // 🔁 Escribe cada carácter en stdout
}

int main(int argc, char **argv)
{
    if (argc == 2)
        rev_print(argv[1]); // 🖨️🔁 Imprime la cadena al revés si se proporciona como argumento
    write(1, "\n", 1); // 📝 Imprime un salto de línea al final
    return 0;
}