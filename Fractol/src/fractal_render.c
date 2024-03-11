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

void	img_pix_put(t_img *img, int x, int y, int color)
{
    char    *pixel;

    pixel = img->pixels_ptr + (y * img->line_len + x * (img->bpp / 8));
    *(int *)pixel = color;
}


float fast_inverse_sqrt(float x)
{
    float xhalf = 0.5f * x;
    int i = *(int *)&x;        // interpret float as int
    i = 0x5f3759df - (i >> 1); // initial guess for Newton's method
    x = *(float *)&i;          // convert new bits into float
    x = x * (1.5f - xhalf * x * x); // One round of Newton's method
    return x;
}


// t_colors sqrt_colors(t_colors *color) 
// {
//     t_colors new_color;

//     new_color->r = (unsigned char)(fast_inverse_sqrt(color->r / 255.0f) * 255.0f);
//     new_color->g = (unsigned char)(fast_inverse_sqrt(color->g / 255.0f) * 255.0f);
//     new_color->b = (unsigned char)(fa(color->b / 255.0f) * 255.0f);

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

    c.x = scale(x, -2, +2, WIDTH);
    c.y = scale(y, -2, +2, HEIGHT);
    while(i < fractal->interations)
    {       
    
        z = sum_complex(square(z), c);
        // printf("%d-->AQUI\n", i);

        if ((z.x * z.x) + (z.y * z.y) > fractal->hypo_value)
        {
            color = scale(i,  BLACK, WHITE, fractal->interations);
            invr_color = fast_inverse_sqrt(color);
            int r = (int)(255.0 * invr_color);
            int g = (int)(255.0 * invr_color);
            int b = (int)(255.0 * invr_color);
            img_pix_put(&fractal->img, x, y, r | g | b);
            return;
        }
        ++i;
    }
    img_pix_put(&fractal->img, x, y, PSYCHEDELIC_0);      
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
        // mlx_pixel_put(fractal->mlx_connection, &fractal->img,x, y,);
        // img_pix_put(&fractal->img, x, y, YELLOW);
        }
    printf("y=%i\n\n\n\n\n\n", y); 
    }
    // mlx_put_image_to_window(fractal->mlx_connection, &fractal->img,)
    mlx_put_image_to_window(fractal->mlx_connection,
                            fractal->mlx_window,
                            fractal->img.img_ptr,
                            0, 0);
printf("y=%i\n", y);}