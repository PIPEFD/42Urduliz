/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbonilla <dbonilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 17:41:56 by dbonilla          #+#    #+#             */
/*   Updated: 2023/12/17 20:42:57 by dbonilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include <math.h>

#ifndef FRACTOL_H
#define FRACTOL_H

#define WIDTH 1920
#define HEIGHT 1080

typedef struct s_complex
{
    double real;
    double imag;
} t_complex;

int		mandelbrot(t_complex c, int max_iter);
void	draw_mandelbrot(void *mlx_ptr, void *win_ptr);
float	fast_inverse_sqrt(float x);
void	draw_pixel(void *mlx_ptr, void *win_ptr, int x, int y, int color);


#endif