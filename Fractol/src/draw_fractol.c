/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fractol.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbonilla <dbonilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 17:38:56 by dbonilla          #+#    #+#             */
/*   Updated: 2023/12/17 20:42:47 by dbonilla         ###   ########.fr       */
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

    for (int x = 0; x < WIDTH; x++)
    {
        for (int y = 0; y < HEIGHT; y++)
        {
            t_complex c = {offset.real + x * zoom, offset.imag + y * zoom};
            int color = mandelbrot(c, max_iter);

            // Puedes ajustar la lógica de color según tus preferencias
            int r = (color % 256) << 16;
            int g = (color % 256) << 8;
            int b = (color % 256);
            draw_pixel(mlx_ptr, win_ptr, x, y, r | g | b);
        }
    }
}

int main()
{
    void *mlx_ptr = mlx_init();
    void *win_ptr = mlx_new_window(mlx_ptr, WIDTH, HEIGHT, "Mandelbrot Set");

    draw_mandelbrot(mlx_ptr, win_ptr);

    mlx_loop(mlx_ptr);

    return 0;
}
