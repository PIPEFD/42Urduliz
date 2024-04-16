/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_power_of_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 14:03:36 by codespace         #+#    #+#             */
/*   Updated: 2024/04/15 13:03:35 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>


// ✨ La función is_power_of_2 verifica si un número es una potencia de 2.
// 🟢 Comienza verificando los casos especiales de 0, 1 y 2.
// 🛑 Luego, verifica si el número es impar.
// 🔁 Después, verifica si el número es divisible por 2 hasta que sea menor que 2.
// 💡 La función devuelve 1 si el número es una potencia de 2 y 0 si no lo es.

// Función para verificar si un número es una potencia de 2
int is_power_of_2(unsigned int n)
{
    // 🟢 Verifica si el número es igual a 1 o 2 (2^0 y 2^1 son potencias de 2)
    if (n == 2 || n == 1)
        return 1; // 🚀 Retorna verdadero

    // 🛑 Verifica si el número es 0
    if (n == 0)
        return 0; // 🛑 Retorna falso

    // 🔄 Verifica si el número es impar
    while (n % 2 == 1)
        return 0; // 🛑 Retorna falso

    // 🔁 Verifica si el número es una potencia de 2
    while (n > 2)
    {
        // 🔄 Si el número no es divisible por 2, entonces no es una potencia de 2
        if (n % 2 == 1)
            return 0; // 🛑 Retorna falso
        n /= 2; // ➗ Divide el número por 2
    }

    return 1; // 🚀 Retorna verdadero
}

// int is_power_of_2(unsigned int n)
// {
//     // 🧠 Un número es una potencia de 2 si tiene un solo bit establecido en su representación binaria.
//     // 🧠 La expresión (n & (n - 1)) despeja el bit más bajo establecido, y si el resultado es 0, significa que solo había un bit establecido.
//     return (n != 0 && ((n & (n - 1)) == 0));
// }
