/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 17:41:56 by dbonilla          #+#    #+#             */
/*   Updated: 2024/01/04 09:59:00 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include <math.h>

#ifndef FRACTOL_H
#define FRACTOL_H

// #define WIDTH 1920
// #define HEIGHT 1080

#define DEV 0
#define MACB 1
#define IMAC 2
#define IMAC4K 3
#define MANDEL 0
#define JULIA   1
#define BURNING 2
#define BURNING_JULIA 3
#define SYM     4
#define SYM_JULIA   5 
#define TYPE_c      unsigned int

#define EXIT_FAILURE 1
#define EXIT_SUCCESS 0


# if (MAC == MACB)
#define WIN_TITLE   "Fractol on Macbook"
#define VP_WIDTH    1680
#define VP_HEIGHT   1000
#define M_XMIN      -2.8
#define M_XMAX      1.3
#define J_X         2
#define BJ_X        3
# elif (MAC == IMAC)
#define WIN_TITLE   "Fractol 42"
#define VP_WIDTH    2650
#define VP_HEIGHT   1400
#define M_XMIN      -2.8
#define M_XMAX      1.3
#define J_X         2.35
#define BJ_X        3
# elif (MAC == IMAC4K)
#define WIN_TITLE   "Fractol"
#define VP_WIDTH    1000
#define VP_HEIGHT   1000
#define M_XMIN      -2.1
#define M_XMAX      0.6
#define J_X         2
#define BJ_X        3

#define MSJ_USAGE "Usage: ./fractol <Mandelbront> <Julia> <Koch>"
#define MSG_BYE     "Leave Fractol. Agur...Agur...!"
#define MSG_ERR     "Error in Fractol"


#define CMD_1      "1 | 2 | 3 => Select Fractal"
#define CMD_2       " P | scrolll -> Color | Zoom"
#define CMD_3       "Arrow | Esc =>  Move | Quit"
#define CMD_4       " R or T + (50) | -F or G (5) => Interation"
#define CMD_5       ""
#define CMD_6
#define CMD_7
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