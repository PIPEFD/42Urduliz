/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 13:39:57 by codespace         #+#    #+#             */
/*   Updated: 2024/04/15 15:21:19 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

// Función para imprimir la primera palabra de una cadena
void first_word(char *s)
{
    // 🔄 Avanza el índice hasta encontrar el primer carácter diferente de espacio o tabulación
    while (*s== 32 || *s == 9 )
        s++;
    
    // 🔄 Mientras el carácter actual no sea un espacio, una tabulación o el final de la cadena
    while (*s != 32 && *s != 9 && *s)
    {
        // ✍️ Escribe el carácter en la salida estándar
        write(1, &*s, 1);
        s++;
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
