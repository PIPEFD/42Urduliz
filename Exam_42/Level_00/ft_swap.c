/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 22:56:25 by codespace         #+#    #+#             */
/*   Updated: 2024/03/28 22:17:12 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Definición de la función ft_swap que intercambia los valores de dos enteros
void ft_swap(int *a, int *b)
{
    int x; // Variable temporal para almacenar el valor de a

    x = *a; // Almacena el valor de a en x
    *a = *b; // Asigna el valor de b a a
    *b = x; // Asigna el valor original de a (almacenado en x) a b
}
