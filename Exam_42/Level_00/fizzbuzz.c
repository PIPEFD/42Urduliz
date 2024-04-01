/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fizzbuzz.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 20:48:55 by codespace         #+#    #+#             */
/*   Updated: 2024/03/30 20:48:57 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

// 🔄 Función recursiva para imprimir un número entero en stdout
int ft_putnbr(int n)
{
    if (n >= 10)
        ft_putnbr(n / 10); // Llamada recursiva para imprimir los dígitos del número
    char c = (n % 10) + '0'; // Obtiene el último dígito y lo convierte en carácter
    write(1, &c, 1); // Escribe el carácter en stdout
}

int main()
{
    int i = 1;
    while (i <= 100)
    {
        if (i % 15 == 0)
            write(1, "fizzbuzz", 8); // Si es divisible por 15, escribe "fizzbuzz"
        else if (i % 3 == 0)
            write(1, "fizz", 4); // Si es divisible por 3, escribe "fizz"
        else if (i % 5 == 0)
            write(1, "buzz", 4); // Si es divisible por 5, escribe "buzz"
        else
            ft_putnbr(i); // Si no es divisible por 3, 5 o ambos, escribe el número
        i++;
        write(1, "\n", 1); // Imprime un salto de línea después de cada número o palabra
    }
}