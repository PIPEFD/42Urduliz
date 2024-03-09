/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipefd <pipefd@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 17:41:56 by dbonilla          #+#    #+#             */
/*   Updated: 2024/03/07 22:48:57 by pipefd           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <unistd.h>
# include <math.h>
# include "../mlx/mlx.h"
# include "../libft/inc/libft.h"

#ifndef FRACTOL_H
#define FRACTOL_H


// #define DEV 0
// #define MANDEL 0
// #define JULIA   1
// #define BURNING 2
// #define BURNING_JULIA 3
// #define SYM     4
// #define SYM_JULIA   5 
// #define TYPE_c      unsigned int

// #define EXIT_FAILURE 1
// #define EXIT_SUCCESS 0



#define WIN_TITLE   "Fractol"
#define WIDTH    	800
#define HEIGHT   	800



#define BLACK       0x000000
#define WHITE       0xFFFFFF
// #define RED         0xFF0000
// #define GREEN       0x00FF00
// #define BLUE        0x0000FF
// #define YELLOW      0xFFFF00
// #define MAGENTA     0xFF00FF
// #define CYAN        0x00FFFF

#define PSYCHEDELIC_0  0xFF1493  // Rosa fuerte
#define PSYCHEDELIC_1  0x9400D3  // Violeta
#define PSYCHEDELIC_2  0x00CED1  // Turquesa
#define PSYCHEDELIC_3  0xFFD700  // Dorado
#define PSYCHEDELIC_4  0x32CD32  // Verde lima
#define PSYCHEDELIC_5  0x8A2BE2  // Azul lavanda

#define MSJ_USAGE "Usage: ./fractol <Mandelbront> <Julia> <Koch>"
#define MSG_BYE     "Leave Fractol. Agur...Agur...!"
#define MSG_ERR     "Error in Fractol \n"


#define CMD_1      "1 | 2 => Select Fractal"
#define CMD_2       " P | scrolll -> Color | Zoom"
#define CMD_3       "Arrow | Esc =>  Move | Quit"
#define CMD_4       
#define CMD_5       
#define CMD_6
#define CMD_7

typedef struct s_window
{
	int	x;
	int	y;
}			t_window;


typedef struct s_complex
{
    double x;
    double y;
} 			t_complex;

typedef struct s_img
{
	void    *img_ptr;
	char    *pixels_ptr;
	int     bpp;
	int     endian;
	int     line_len;
} 				t_img;

typedef struct s_fractal
{
	char	*name;
	void	*mlx_connection;
	void	*mlx_window;
	t_img	img;
	double	hypo_value;
	int		interations;
}				t_fractal;




void    	fractal_init(t_fractal *fractal);
double 		scale(double unscaled_num, double new_min, double new_max, double old_min, double old_max);
void    	fractal_render(t_fractal *fractal);
t_complex 	sum_complex(t_complex z1, t_complex z2);
t_complex 	square(t_complex z);




#endif