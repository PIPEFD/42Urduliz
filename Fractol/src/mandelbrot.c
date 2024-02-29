/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 17:39:04 by dbonilla          #+#    #+#             */
/*   Updated: 2024/02/29 08:01:13 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

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


void draw_mandelbrot(void *mlx_ptr, void *win_ptr)
{
    int max_iter = 100; // Puedes ajustar esto según tus necesidades
    double zoom = 0.004;
    t_complex offset = {-2, -1.5};
    int x;
    int y;
    x = 0;
    
    while(x++ < WIDTH)
    {
        y = 0;
        while (y++ < HEIGHT)
        {


        t_complex c = {offset.real + x * zoom, offset.imag + y * zoom};
        int color = mandelbrot(c, max_iter);

        float inv_sqrt_color = fast_inverse_sqrt(color);
        int r = (int)(255.0 * inv_sqrt_color);
        int g = (int)(255.0 * inv_sqrt_color);
        int b = (int)(255.0 * inv_sqrt_color);
        draw_pixel(mlx_ptr, win_ptr, x, y, r << 16 | g << 8 | b);
        }
    }
}

        //     // Puedes ajustar la lógica de color según tus preferencias
        //     int r = (color % 256) << 16;
        //     int g = (color % 256) << 8;
        //     int b = (color % 256);
        //  draw_pixel(mlx_ptr, win_ptr, x, y, r | g | b);
        // }