/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 11:41:27 by codespace         #+#    #+#             */
/*   Updated: 2024/03/30 14:23:37 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Función para verificar si un carácter es un espacio en blanco
int is_blank(char c)
{
    if (c <= 32)
        return(1); // Retorna 1 si es espacio en blanco
    return(0); // Retorna 0 si no es espacio en blanco
}

// Función para verificar si un carácter es un dígito válido en la base dada
int is_valid(char c, int base)
{
    char dgt_1[17] = "0123456789abcdef"; // Dígitos hexadecimales minúsculos
    char dgt_2[17] = "0123456789ABCDEF"; // Dígitos hexadecimales mayúsculos
    while (base--)
        if (dgt_1[base] == c || dgt_2[base] == c)
            return (1); // Retorna 1 si el carácter es un dígito válido
    return (0); // Retorna 0 si no es un dígito válido
}

// Función que devuelve el valor numérico de un carácter en base hexadecimal
int ft_value(char c)
{
    if (c >= '0' && c <= '9')
        return (c - '0'); // Retorna el valor numérico del dígito
    else if (c >= 'a' && c <= 'f')
        return (c - 'a' + 10); // Retorna el valor numérico de la letra minúscula en hexadecimal
    else if (c >= 'A' && c <= 'F')
        return (c - 'A' + 10); // Retorna el valor numérico de la letra mayúscula en hexadecimal
    return (0); // Retorna 0 si el carácter no es un dígito hexadecimal válido
}

// Función para convertir una cadena en un entero en la base especificada
int ft_atoi_base(char const *str, int base)
{
    int result = 0; // Inicializa el resultado como 0
    int sign; // Variable para almacenar el signo del número
    
    // Ignora los espacios en blanco al principio de la cadena
    while (is_blank(*str))
        str++;
    
    // Determina el signo del número
    sign = (*str == '-') ? -1 : 1; // 🔄 Si el primer carácter es '-', establece el signo como negativo
    (*str == '-' || *str == '+') ? str++ : 0; // 🛣️ Si el primer carácter es '-' o '+', avanza al siguiente carácter
    
    // Convierte la cadena en un entero en la base especificada
    while (is_valid(*str, base)) // 🔄 Mientras el carácter sea válido en la base especificada
        result = result * base + ft_value(*str++); // 🔢 Actualiza el resultado con el valor numérico del carácter
    
    return(result  * sign); // Retorna el número convertido con su signo
}

// Función para convertir una cadena en un entero
int ft_atoi(char *s)
{
    int i = 0;
    int sign = 1; // Inicializa el signo como positivo
    int result = 0; // Inicializa el resultado como 0

    // Ignora los espacios en blanco al principio de la cadena
    while (s[i] == 32 || (s[i] >= 9 && s[i] <= 13))
        i++;
    
    // Determina el signo del número
    if (s[i] == '-' || s[i] == '+')
        sign = (s[i++] == '-') ? -1 : 1; // 🔄 Si el primer carácter es '-', establece el signo como negativo y avanza al siguiente carácter
    
    // Convierte la parte numérica de la cadena en un entero
    while (s[i] >= '0' && s[i] <= '9') // 🔄 Mientras el carácter sea un dígito
        result = result * 10 + s[i++] - '0'; // 🔢 Actualiza el resultado con el valor numérico del carácter
    
    return (result * sign); // Retorna el número convertido con su signo
}

// // Función principal
// int main(int argc, char **argv)
// {
//     // Verifica si se proporcionaron dos argumentos en la línea de comandos
//     if (argc == 3)
//         printf("%d\n", ft_atoi_base(argv[1], ft_atoi(argv[2]))); // Imprime el resultado de la conversión
//     return (0);
// }
