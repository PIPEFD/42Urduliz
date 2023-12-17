/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbonilla <dbonilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 17:39:04 by dbonilla          #+#    #+#             */
/*   Updated: 2023/12/17 20:25:07 by dbonilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fract'ol.h"

int mandelbrot(t_complex c, int max_iter)
{
    t_complex z = {0, 0};
    int iter = 0;

    while (iter < max_iter && (z.real * z.real + z.imag * z.imag) < 4)
    {
        double temp = z.real * z.real - z.imag * z.imag + c.real;
        z.imag = 2 * z.real * z.imag + c.imag;
        z.real = temp;
        iter++;
    }
    return iter;
}