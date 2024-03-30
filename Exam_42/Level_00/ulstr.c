/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ulstr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 11:50:55 by codespace         #+#    #+#             */
/*   Updated: 2024/03/30 11:51:38 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ulstr(char *s)
{
    int i = 0;

    // Recorre la cadena de caracteres
    while (s[i])
    {
        // Si el carácter es una minúscula, conviértelo a mayúscula
        if (s[i] >= 'a' && s[i] <= 'z')
            s[i] = s[i] - 32; // 🔄 Convertir a mayúscula
        // Si el carácter es una mayúscula, conviértelo a minúscula
        else if (s[i] >= 'A' && s[i] <= 'Z')
            s[i] = s[i] + 32; // 🔄 Convertir a minúscula
        
        // Escribe el carácter modificado en la salida estándar
        write(1, &s[i], 1); // ✍️ Escribir en la salida estándar
        
        // Incrementa el índice para pasar al siguiente carácter
        i++;
    }
}

int main(int argc, char **argv)
{
    // Verifica si se proporcionó un argumento de línea de comandos
    if (argc == 2)
        // Llama a la función ulstr con el argumento proporcionado
        ulstr(argv[1]);

    // Escribe un salto de línea al final del resultado
    write(1, "\n", 1); // 📝 Salto de línea
    
    return 0;
}