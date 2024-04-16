/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 12:06:33 by codespace         #+#    #+#             */
/*   Updated: 2024/04/15 16:09:16 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

// 🔁 Función para imprimir una cadena al revés en stdout
void rev_print(char *s)
{
    char start = s; // 📌 Guarda la dirección de inicio de la cadena
    
    while (*s != '\0') // 🔁 Encuentra el final de la cadena
    {
        s++; // ➡️ Avanza al siguiente carácter
    }
    s--; // 🔻 Retrocede un carácter para apuntar al último carácter de la cadena
    while (s >= start) // 🔁 Imprime la cadena al revés
        write(1, &s, 1); // 🖨️🔁 Escribe cada carácter en stdout
}

int main(int argc, char **argv)
{
    if (argc == 2)
        rev_print(argv[1]); // 🖨️🔁 Imprime la cadena al revés si se proporciona como argumento
    write(1, "\n", 1); // 📝 Imprime un salto de línea al final
    return 0;
}