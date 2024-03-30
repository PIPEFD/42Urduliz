/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 18:05:01 by codespace         #+#    #+#             */
/*   Updated: 2024/03/30 14:22:47 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

// Función para convertir una cadena de caracteres a un entero
int ft_atoi(const char *s)
{
    int result = 0; // Almacena el resultado de la conversión
    int sign = 1;   // Almacena el signo del número (1 para positivo, -1 para negativo)

    // Ignora los espacios en blanco y caracteres de control al inicio de la cadena
    while (*s == ' ' || (*s >= 9 && *s <= 13))
        s++;

    // Determina el signo del número
    // Ignora el signo '+' o '-' si está presente
    if (*s == '-' || *s == '+')
        sign = (*s++ == '-') ? -1 : 1;
    // Convierte los dígitos de la cadena en un entero
    while (*s >= '0' && *s <= '9')
    {
        result = result * 10 + *s++ - '0'; // Multiplica el resultado actual por 10 y suma el dígito
                                          // Avanza al siguiente carácter de la cadena
    }

    return (sign * result); // Retorna el número con su signo correspondiente
}

int main(void)
{
    char const str[11] = "0123456789"; // Cadena de caracteres a convertir
    char const str2[11] = "0123456789"; // Cadena de caracteres para comparación con atoi

    // Imprime el resultado de la función personalizada ft_atoi
    printf("El resultado de ft_atoi es: %d\n", ft_atoi(str));

    // Imprime el resultado de la función atoi para comparación
    printf("El resultado de atoi es: %d\n", atoi(str2));

    return (0); // Retorna 0 para indicar que el programa se ejecutó correctamente
}
