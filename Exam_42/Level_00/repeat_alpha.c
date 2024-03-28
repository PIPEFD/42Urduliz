/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 17:33:22 by codespace         #+#    #+#             */
/*   Updated: 2024/03/28 22:18:30 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

// Función para repetir cada carácter alfabético de acuerdo a su posición en el alfabeto
void repeat_alpha(char *s)
{
    int i = 0; // Índice para recorrer la cadena
    int repeat; // Variable para determinar cuántas veces se debe repetir cada carácter

    // 🔄 Itera sobre la cadena hasta encontrar el carácter nulo que indica el final de la cadena
    while (s[i])
    {
        repeat = 1; // Inicializa el número de repeticiones como 1
        
        // 📌 Si el carácter es una letra minúscula
        if (s[i] >= 'a' && s[i] <= 'z')
            // 📊 Calcula el número de repeticiones basado en la posición del carácter en el alfabeto
            repeat += s[i] - 'a';
        // 📌 Si el carácter es una letra mayúscula
        else if (s[i] >= 'A' && s[i] <= 'Z')
            // 📊 Calcula el número de repeticiones basado en la posición del carácter en el alfabeto
            repeat += s[i] - 'A';
        
        // 🔄 Repite el carácter actual el número de veces determinado por 'repeat'
        while (repeat)
        {
            // ✍️ Escribe el carácter en la salida estándar
            write(1, &s[i], 1);
            repeat--; // 🔻 Decrementa el número de repeticiones restantes
        }
        i++; // ➡️ Avanza al siguiente carácter en la cadena
    }
}

// Función principal
int main (int argc, char **argv)
{
    // 🔍 Verifica si se proporcionó un argumento al programa
    if (argc == 2)
        // 📌 Llama a la función repeat_alpha con el primer argumento como entrada
        repeat_alpha(argv[1]);
    
    // ✏️ Escribe un salto de línea en la salida estándar
    write(1, "\n", 1);
    return(0);
}
