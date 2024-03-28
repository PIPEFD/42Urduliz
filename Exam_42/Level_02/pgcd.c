/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pgcd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 23:16:18 by codespace         #+#    #+#             */
/*   Updated: 2024/03/28 23:16:19 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

// Función para calcular el máximo común divisor (PGCD) de dos números
void pgcd(char *a, char *b)
{
    int i = atoi(a); // 📌 Convierte el primer argumento a entero
    int j = atoi(b); // 📌 Convierte el segundo argumento a entero

    // 🧠 Verifica que ambos números sean positivos
    if (i > 0 && j > 0)
    {
        // 🔄 Algoritmo para encontrar el PGCD usando el método de Euclides
        while (i != j)
        {
            if (i > j)
                i = i - j;
            else
                j = j - i;
        }
        // 🖨️ Imprime el PGCD calculado
        printf("%d", i);
    }
}

int main(int argc, char **argv)
{
    // 🧠 Verifica que se proporcionen exactamente 2 argumentos (los números)
    if (argc == 3)
        pgcd(argv[1], argv[2]); // 🧠 Llama a la función pgcd con los dos números como argumentos
    printf("\n"); // 🖨️ Imprime un salto de línea al final
    return 0;
}
