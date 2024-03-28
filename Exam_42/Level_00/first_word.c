/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 13:39:57 by codespace         #+#    #+#             */
/*   Updated: 2024/03/28 22:13:17 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

// Función para imprimir la primera palabra de una cadena
void first_word(char *s)
{
    int i = 0;
    
    // 🔄 Avanza el índice hasta encontrar el primer carácter diferente de espacio o tabulación
    while (s[i] == 32 || s[i] == 9 )
        s[i]++;
    
    // 🔄 Mientras el carácter actual no sea un espacio, una tabulación o el final de la cadena
    while (s[i] != 32 && s[i] != 9 && s[i])
    {
        // ✍️ Escribe el carácter en la salida estándar
        write(1, &s[i], 1);
        i++;
    }
}

int main(int argc, char **argv)
{
    // 🔍 Verifica si se proporcionó un argumento al programa
    if (argc == 2)
        // 📌 Llama a la función first_word con el primer argumento como entrada
        first_word(argv[1]);
    
    // ✏️ Escribe un salto de línea en la salida estándar
    write(1, "\n", 1);
    return(0);
}


// Examples:

// $> ./first_word "FOR PONY" | cat -e
// FOR$
// $> ./first_word "this        ...       is sparta, then again, maybe    not" | cat -e
// this$
// $> ./first_word "   " | cat -e
// $
// $> ./first_word "a" "b" | cat -e
// $
// $> ./first_word "  lorem,ipsum  " | cat -e
// lorem,ipsum$
// $>