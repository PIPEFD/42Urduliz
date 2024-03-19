/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_render.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbonilla <dbonilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 21:41:33 by pipefd            #+#    #+#             */
/*   Updated: 2024/03/19 03:47:47 by dbonilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	img_pix_put(t_img *img, int x, int y, int color)
{
	char	*pixel;

	pixel = img->pixels_ptr + (y * img->line_len + x * (img->bpp / 8));
	*(int *)pixel = color;
}

void	mandel_vs_julia(t_complex *c, t_complex *z, t_fractal *fractal)
{
	if (!ft_strncmp(fractal->name, "julia", 6))
	{
		c->x = fractal->julia_x;
		c->y = fractal->julia_y;
	}
	if (!ft_strncmp(fractal->name, "mandelbrot", 11))
	{
		c->x = z->x;
		c->y = z->y;
	}
}

static void	take_pixel(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	int			color;
	int			i;

	color = 0;
	i = 0;
	z.x = (scale(x, -2.0, +2.0, WIDTH) * fractal->move.zoom) \
						+ fractal->move.x_ran;
	z.y = (scale(y, +2.0, -2.0, HEIGHT) * fractal->move.zoom) \
						+ fractal->move.y_ran;
	mandel_vs_julia(&c, &z, fractal);
	while (++i < fractal->interations)
	{
		z = sum_complex(square(z), c);
		if ((z.x * z.x) + (z.y * z.y) > fractal->hypo_value)
		{
			color = scale(i, BLACK_2, WHITE_2, fractal->interations);
			mlx_get_color_value(fractal->mlx_connection, color);
			img_pix_put(&fractal->img, x, y, (color * (i / 2)));
			return ;
		}
	}
	img_pix_put(&fractal->img, x, y, (color * (i / 2)));
}

void	fractal_render(t_fractal *fractal)
{
	int	x;
	int	y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			take_pixel(x, y, fractal);
		}
	}
	mlx_clear_window(fractal->mlx_connection, fractal->mlx_window);
	mlx_put_image_to_window(fractal->mlx_connection, \
							fractal->mlx_window, \
							fractal->img.img_ptr, \
							0, 0);
}
