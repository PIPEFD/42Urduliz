/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fractol.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbonilla <dbonilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 17:38:56 by dbonilla          #+#    #+#             */
/*   Updated: 2023/12/23 21:00:58 by dbonilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	draw_pixel(void *mlx_ptr, void *win_ptr, int x, int y,int color)
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
