/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fractol.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 17:38:56 by dbonilla          #+#    #+#             */
/*   Updated: 2023/12/22 08:08:03 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void draw_pixel(void *mlx_ptr, void *win_ptr, int x, int y, int color)
{
    mlx_pixel_put(mlx_ptr, win_ptr, x, y, color);
}


void draw_mandelbrot(void *mlx_ptr, void *win_ptr)
{
    int max_iter = 100; // Puedes ajustar esto según tus necesidades
    double zoom = 0.004;
    t_complex offset = {-2, -1.5};
    int x;
    int y;
    x = 0;
    y = 0;
    
    while(x < WIDTH)
    {
        while (y < HEIGHT)
        {


        t_complex c = {offset.real + x * zoom, offset.imag + y * zoom};
        int color = mandelbrot(c, max_iter);

        float inv_sqrt_color = fast_inverse_sqrt(color);
        int r = (int)(255.0 * inv_sqrt_color);
        int g = (int)(255.0 * inv_sqrt_color);
        int b = (int)(255.0 * inv_sqrt_color);
        draw_pixel(mlx_ptr, win_ptr, x, y, r << 16 | g << 8 | b);
        y++;
        }
        x++;
    }
}

        //     // Puedes ajustar la lógica de color según tus preferencias
        //     int r = (color % 256) << 16;
        //     int g = (color % 256) << 8;
        //     int b = (color % 256);
        //  draw_pixel(mlx_ptr, win_ptr, x, y, r | g | b);
        // }
int main()
{
    void *mlx_ptr = mlx_init();
    void *win_ptr = mlx_new_window(mlx_ptr, WIDTH, HEIGHT, "Mandelbrot Set");

    draw_mandelbrot(mlx_ptr, win_ptr);

    mlx_loop(mlx_ptr);

    return 0;
}
