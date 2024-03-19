/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbonilla <dbonilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 17:41:56 by dbonilla          #+#    #+#             */
/*   Updated: 2024/03/19 03:40:06 by dbonilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <unistd.h>
# include <math.h>
# include "../mlx/mlx.h"
# include "../libft/inc/libft.h"

# define WIN_TITLE   "Fractol"
# define WIDTH    	800
# define HEIGHT   	800
# define BLACK_2    0x000000
# define WHITE_2	0xFFFFFF
# define RED_2      0xFF0000
# define GREEN_2  	0x00FF00
# define BLUE_2   	0x0000FF
# define YELLOW_2 	0xFFFF00
# define MAGENTA_2	0xFF00FF
# define CYAN_2   	0x00FFFF
# define PSYCHEDELIC_0  0xFF1493  // Rosa fuerte
# define PSYCHEDELIC_1  0x9400D3  // Violeta
# define PSYCHEDELIC_2  0x00CED1  // Turquesa
# define PSYCHEDELIC_3  0xFFD700  // Dorado
# define PSYCHEDELIC_4  0x32CD32  // Verde lima
# define PSYCHEDELIC_5  0x8A2BE2  // Azul lavanda
# define MSG_N "INVALID ARGUMENTS!\n \
			SELECT \
----->./fractol mandelbrot<-----\n \
--------->./fractol julia\n<--------\
		 		JULIA\n \
		   SET <-1> - <1>\n"
# define MSG_ERR "Error: malloc failed\n"

typedef struct s_movement
{
	double	x_ran;
	double	y_ran;
	double	zoom;
	double	c_r;
	double	c_i;
}				t_movement;

typedef struct s_complex
{
	double	x;
	double	y;
}		t_complex;

typedef struct s_img
{
	void	*img_ptr;
	char	*pixels_ptr;
	int		bpp;
	int		endian;
	int		line_len;
}			t_img;

typedef struct s_fractal
{
	int			argc;
	char		**argv;
	char		*name;
	void		*mlx_connection;
	void		*mlx_window;
	t_img		img;
	double		color;
	double		julia_x;
	double		julia_y;
	double		hypo_value;
	int			interations;
	t_movement	move;
}				t_fractal;
void		fractal_init(t_fractal *fractal);
void		fractal_render(t_fractal *fractal);
void		mandel_vs_julia(t_complex *c, t_complex *z, t_fractal *fractal);
void		data_init(t_fractal *fractal);
void		img_pix_put(t_img *img, int x, int y, int color);
void		show_hud(t_fractal *fractal);
void		events_init(t_fractal *fractal);
int			close_handler(t_fractal *fractal);
int			deal_keyboard(int key_code, t_fractal *fractal);
int			mouse_hook(int key_code, int x, int y, t_fractal *fractal);
double		scale(double unscaled_num, double newmin, \
			double newmax, double oldmax);
t_fractal	*relative_posi(int keycode, int x, int y, t_fractal *fractal);
t_complex	sum_complex(t_complex z1, t_complex z2);
t_complex	square(t_complex z);

#endif