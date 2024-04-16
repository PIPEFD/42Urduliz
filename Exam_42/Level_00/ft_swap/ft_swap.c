/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 22:56:25 by codespace         #+#    #+#             */
/*   Updated: 2024/04/15 15:58:18 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

// Definición de la función ft_swap que intercambia los valores de dos enteros
void ft_swap(int *a, int *b)
{
    int swap; // Variable temporal para almacenar el valor de a

    swap = *a; // Almacena el valor de a en x
    *a = *b; // Asigna el valor de b a a
    *b = swap; // Asigna el valor original de a (almacenado en x) a b
}

int main (void)
{
    int a = 21; // Inicializa la variable a con el valor 21
    int b = 42; // Inicializa la variable b con el valor 42
    printf("a = %d -> b = %d\n", a, b); // Imprime los valores de a y b
    ft_swap(&a, &b);
    printf("a = %d <- b = %d\n", a, b); // Imprime los valores de a y b
    return (0);
}