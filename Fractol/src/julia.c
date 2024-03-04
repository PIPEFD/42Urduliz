/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: event <event@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 17:39:01 by dbonilla          #+#    #+#             */
/*   Updated: 2024/03/04 15:58:35 by event            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

// int julia(t_complex c, int max_iter)
// {
//     int iter = 1;
//     t_complex z = {0, 0};
    
//     while (iter < max_iter && (z.real * z.real + z.imag * z.imag) < 4)
//     {
//         double temp = z.real * z.real - z.imag * z.imag + c.real;
//         double z_real_original = z.real; // Guarda el valor original de z.real
//         z.imag = 2 * z_real_original * z.imag + c.imag; // Utiliza el valor original de z.real
//         z.real = temp;
//         iter++;
//     }

//     return iter;
// }
// void draw_julia(void *mlx_ptr, void *win_ptr)
// {
//     int max_iter = 100;
//     double zoom = 0.004;
//     t_complex offset = {-2, -1.5};
//     int x = 0;
//     int y;

//     while (x < WIDTH)
//     {
//         y = 0; // Restablece y a 0 en cada iteración de x
//         while (y < HEIGHT)
//         {
//             t_complex c = {offset.real + x * zoom, offset.imag + y * zoom};
//             int color = julia(c, max_iter);

//             float inv_sqrt_color = fast_inverse_sqrt(color);
//             int r = (int)(255.0 * inv_sqrt_color);
//             int g = (int)(255.0 * inv_sqrt_color);
//             int b = (int)(255.0 * inv_sqrt_color);
//             draw_pixel(mlx_ptr, win_ptr, x, y, r << 16 | g << 8 | b);

//             y++; // Incrementa y dentro del bucle interno
//         }
//         x++; // Incrementa x dentro del bucle externo
//     }
// }


int julia(t_complex z, t_complex c, int max_iter)
{
    int iter = 1;
    
    while (iter < max_iter && (z.real * z.real + z.imag * z.imag) < 4)
    {
        double temp = z.real * z.real - z.imag * z.imag + c.real;
        z.imag = 2 * z.real * z.imag + c.imag;
        z.real = temp;
        iter++;
    }

    return iter;
}

void draw_julia(void *mlx_ptr, void *win_ptr)
{
    int max_iter = 100;
    double zoom = 0.004;
    t_complex offset = {-2, -1.5};
    int x = 0;
    int y;

    while (x < WIDTH)
    {
        y = 0;
        while (y < HEIGHT)
        {
            t_complex c = {offset.real + x * zoom, offset.imag + y * zoom};

            t_complex c_fixed = {0.285, 0.01};

            int color = julia(c, c_fixed, max_iter);

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
