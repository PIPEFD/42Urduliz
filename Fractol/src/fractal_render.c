/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_render.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipefd <pipefd@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 21:41:33 by pipefd            #+#    #+#             */
/*   Updated: 2024/03/07 22:47:48 by pipefd           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void draw_pixel(int x , int y, t_img *img, int color)
{
    int     offset;

    offset  = (y * img->line_len) + (x * (img->bpp / 8));
    *(unsigned int *)(img->pixels_ptr + offset) = color;
}




static void take_pixel(int x, int y, t_fractal *fractal)
{
    t_complex   z;
    t_complex   c;
    int         i;
    int         color;
    
    i = 0;
    z.x = 0.0;
    z.y = 0.0;

    c.x = scale(x, -2, +2, 0, WIDTH);
    c.y = scale(y, +2, -2, 0, HEIGHT);

    while(i < fractal->interations)
    {
    
        z = sum_complex(square(z), c);
        
        if ((z.x * z.x) + (z.y * z.y) > fractal->hypo_value)
        {
            color = scale(i,  BLACK, WHITE, 0, fractal->interations);
            draw_pixel(x, y, &fractal->img, color);
            return;
        }
        ++i;
    }
    draw_pixel(x, y, &fractal->img, PSYCHEDELIC_0);
    
        
    
    
}

void    fractal_render(t_fractal *fractal)
{
    int x;
    int y;

    y = -1;
    while (++y < HEIGHT)
    {
        x = -1;
        while (++x < WIDTH)
        {
            take_pixel(x, y, fractal);
        }
    }
    mlx_put_image_to_window(fractal->mlx_connection,
                            fractal->mlx_window,
                            fractal->img.img_ptr,
                            0, 0);
}