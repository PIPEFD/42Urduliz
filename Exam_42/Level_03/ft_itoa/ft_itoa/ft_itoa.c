/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 20:05:13 by codespace         #+#    #+#             */
/*   Updated: 2024/04/16 15:37:12 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdlib.h>

char    *ft_itoa(int nbr) // 📝 Función para convertir un entero a una cadena
{
    int		len; // 📏 Longitud de la cadena resultante
    long	n_tmp; // 🔄 Copia temporal del número
    char	*str; // 📝 Cadena resultante

    len = 0; // 📏 Inicializa la longitud a 0
    n_tmp = nbr; // 🔄 Guarda una copia del número
    if (nbr == -2147483648) // 🚫 Caso especial para el entero más pequeño
        return ("-2147483648");
    if (!(str = (char *)malloc(sizeof(char) * len + 1))) // 💾 Asigna memoria para la cadena
        return (NULL); // 🚫 Si la asignación falla, devuelve NULL
    str[len] ='\0'; // 🚧 Coloca el carácter nulo al final de la cadena
    if (nbr == 0) // 🚫 Caso especial para 0
    {
        str[0] = '0'; // 📝 Escribe '0' en la cadena
        return (str); // 📤 Devuelve la cadena
    }
    if (nbr < 0) // 🔍 Si el número es negativo
    {
        len += 1; // 📏 Aumenta la longitud para el signo '-'
        nbr *= -1; // 🔄 Convierte el número a positivo
        str[0] = '-'; // 📝 Escribe el signo '-' en la cadena
    }
    while (n_tmp) // 🔁 Mientras que la copia del número no sea 0
    {
        n_tmp /= 10; // 🔄 Divide la copia del número por 10
        len += 1; // 📏 Aumenta la longitud
    }
    while (nbr) // 🔁 Mientras que el número no sea 0
    {
        str[--len] = (nbr % 10) + '0'; // 📝 Escribe el dígito actual en la cadena
        nbr /= 10; // 🔄 Divide el número por 10
    }
    return (str); // 📤 Devuelve la cadena resultante
}