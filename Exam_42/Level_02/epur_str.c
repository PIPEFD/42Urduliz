/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   epur_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 23:03:42 by codespace         #+#    #+#             */
/*   Updated: 2024/03/28 23:04:27 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <unistd.h>

// Función para saltar los espacios en blanco y tabulaciones en una cadena a partir de la posición dada
int skip_whitespace(char *s, int i)
{
    while (s[i] == ' ' || s[i] == '\t') // 🔄 Mientras el carácter actual sea un espacio en blanco o una tabulación
        ++i; // ➡️ Avanza al siguiente carácter
    return(i); // Retorna la posición final después de saltar los espacios en blanco y tabulaciones
}

// Función para calcular la longitud de la siguiente palabra en una cadena
int ft_word_len(char *s)
{
    int i = 0;
    while (s[i] != '\0' && s[i] != ' ' && s[i] != '\t') // 🔄 Mientras no se alcance el final de la cadena y no se encuentre un espacio en blanco o tabulación
        ++i; // ➡️ Avanza al siguiente carácter
    return (i); // Retorna la longitud de la palabra
}

// Función para eliminar los espacios en blanco extra de una cadena
void epur_str(char *s)
{
    int i = 0;
    int first_word = 1; // Variable para indicar si es la primera palabra
    int word_len;
    i = skip_whitespace(s, i); // Salta los espacios en blanco al principio de la cadena
    while(s[i] != '\0') // 🔄 Mientras no se alcance el final de la cadena
    {
        if (first_word == 0) // 🤔 Si no es la primera palabra
            write(1, " ", 1); // 🖊️ Escribe un espacio en blanco antes de la palabra
        word_len = ft_word_len(s + i); // Calcula la longitud de la palabra actual
        write(1, s + i, word_len); // 🖊️ Escribe la palabra en la salida estándar
        i = i + word_len; // ➡️ Avanza al siguiente carácter después de la palabra
        first_word = 0; // 🔒 Marca que ya no es la primera palabra
        i = skip_whitespace(s, i); // Salta los espacios en blanco después de la palabra
    }
}

// Función principal
int main(int argc, char **argv)
{
    if (argc == 2) // 🤔 Si se proporciona exactamente un argumento en la línea de comandos
        epur_str(argv[1]); // 🧹 Limpia la cadena de espacios en blanco extra
    write(1, "\n", 1); // 🖊️ Escribe un salto de línea
    return(0); // Termina el programa
}
