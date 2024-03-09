/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_render.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 21:41:33 by pipefd            #+#    #+#             */
/*   Updated: 2024/03/09 23:03:17 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void draw_pixel(int x , int y, t_img *img, int color)
{
    int     offset;

    offset  = (y * img->line_len) + (x * (img->bpp / 8));
    *(unsigned int *)(img->pixels_ptr + offset) = color;
}


float inverse_sqrt(float number) {
    long i;
    float x2, y;
    const float threehalfs = 1.5f;

    x2 = number * 0.5f;
    y  = number;
    i  = *(long *) &y;
    i  = 0x5f3759df - (i >> 1);
    y  = *(float *) &i;
    y  = y * (threehalfs - (x2 * y * y));

    return y;
}


// t_colors sqrt_colors(t_colors *color) 
// {
//     t_colors new_color;

//     new_color->r = (unsigned char)(inverse_sqrt(color->r / 255.0f) * 255.0f);
//     new_color->g = (unsigned char)(inverse_sqrt(color->g / 255.0f) * 255.0f);
//     new_color->b = (unsigned char)(inverse_sqrt(color->b / 255.0f) * 255.0f);

//     return (new_color);
// }


static void take_pixel(int x, int y, t_fractal *fractal)
{
    t_complex   z;
    t_complex   c;
    int         i;
    int         color;
    float       invr_color;
    
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
            invr_color = inverse_sqrt(color);
            int r = (int)(255.0 * invr_color);
            int g = (int)(255.0 * invr_color);
            int b = (int)(255.0 * invr_color);
            draw_pixel(x, y, &fractal->img, r | g | b);
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