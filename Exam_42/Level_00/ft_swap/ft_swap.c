/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 22:56:25 by codespace         #+#    #+#             */
/*   Updated: 2024/07/09 17:18:58 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

// Función ft_swap que intercambia los valores de dos enteros
void ft_swap(int *a, int *b)
{
    int swap;

    swap = *a;
    *a = *b;
    *b = swap;
}

int main (void)
{
    int a = 21;
    int b = 42;
    printf("a = %d -> b = %d\n", a, b);
    ft_swap(&a, &b);
    printf("a = %d <- b = %d\n", a, b);
    return (0);
}