/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 17:39:01 by dbonilla          #+#    #+#             */
/*   Updated: 2023/12/22 09:05:34 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int julia(t_complex z, t_complex c, int max_iter)
{
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

void draw_julia(void *mlx_ptr, void *win_ptr, t_complex c)
{
    int max_iter = 100;
    double zoom = 0.004;
    t_complex offset = {-2, -1.5};
    int x;
    int y;
    x = 0;
    y = 0;
    while (x < WIDTH)
    {
        while (y < HEIGHT)
        {
            t_complex z = {offset.real + x * zoom, offset.imag + y * zoom};
            int color = julia(z, c, max_iter);

            // Ajustar la lógica de color según tus preferencias
            int r = (color % 256) << 16;
            int g = (color % 256) << 8;
            int b = (color % 256);

            draw_pixel(mlx_ptr, win_ptr, x, y, r | g | b);
        y++;
        }
     x++;
    }
}