/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_word.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 23:14:27 by codespace         #+#    #+#             */
/*   Updated: 2024/03/28 23:14:28 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

// Función para imprimir la última palabra de una cadena
void last_word(char *s)
{
    int i = 0;

    // 🔍 Encuentra el final de la cadena
    while (s[i] != '\0')
        i++;

    // 🔄 Retrocede hasta encontrar el primer carácter que no sea un espacio o tabulación
    i--;
    while ((s[i] == ' ' || s[i] == '\t') && i != 0)
        i--;

    // 🔄 Retrocede hasta el inicio de la última palabra
    while (s[i] != ' ' && s[i] != '\t' && i != 0)
        i--;

    // 🛑 Si el último carácter es un espacio o tabulación, avanza una posición
    if (s[i] == ' ' || s[i] == '\t')
        i++;

    // ✍️ Imprime la última palabra
    while (s[i] != '\0' && s[i] != ' ' && s[i] != '\t')
    {   
        write(1, &s[i], 1);
        i++;
    }
}

int main(int argc, char **argv)
{
    if (argc ==  2)
        last_word(argv[1]); // 🧠 Llama a la función last_word con el argumento pasado
    write(1, "\n", 1); // 📝 Imprime un salto de línea al final
    return 0;
}
