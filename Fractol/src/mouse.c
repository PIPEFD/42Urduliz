/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbonilla <dbonilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 12:10:01 by codespace         #+#    #+#             */
/*   Updated: 2024/03/18 21:19:54 by dbonilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"
#include "keycode_mac.h"

t_fractal	*relative_posi(int keycode, int x, int y, t_fractal *fractal)
{
	if (keycode == 4)
	{
		fractal->move.c_r = (fractal->move.c_r \
				+ ((WIDTH - (WIDTH / 0.5)) / 2) \
				+ (x - WIDTH / 2) * (1 - (1 / 0.5))) * 0.5;
		fractal->move.c_i = (fractal->move.c_i \
				+ ((HEIGHT - (HEIGHT / 0.5)) / 2) \
				+ (y - HEIGHT / 2) * (1 - (1 / 0.5))) * 0.5;
		return (fractal);
	}
	else if (keycode == 5)
	{
		fractal->move.c_r = (fractal->move.c_r \
						+ ((WIDTH - (WIDTH * 0.5)) / 2) \
						+ (x - WIDTH / 2) * (1 - 0.5)) + 0.5;
		fractal->move.c_i = (fractal->move.c_i \
						+ ((HEIGHT - (HEIGHT * 0.5)) / 2) \
						+ (y - HEIGHT / 2) * (1 - 0.5)) + 0.5;
		return (fractal);
	}
	return (0);
}

int	mouse_hook(int key_code, int x, int y, t_fractal *fractal)
{
	t_fractal	new_img;

	new_img = *(t_fractal *)fractal;
	if (key_code == 4)
	{
		mlx_clear_window(new_img.mlx_window, new_img.mlx_window);
		fractal->move.zoom /= +0.5;
		new_img = *relative_posi(key_code, x, y, fractal);
		fractal_render(&new_img);
		mlx_put_image_to_window(fractal->mlx_connection, \
								fractal->mlx_window, &fractal->img, 0, 0);
		*(t_fractal *)fractal = new_img;
	}
	else if (key_code == 5)
	{
		mlx_clear_window(new_img.mlx_window, new_img.mlx_window);
		fractal->move.zoom *= 0.5;
		new_img = *relative_posi(key_code, x, y, fractal);
		fractal_render(&new_img);
		mlx_put_image_to_window(fractal->mlx_connection, fractal->mlx_window, \
								&fractal->img, 0, 0);
		*(t_fractal *)fractal = new_img;
	}
	return (0);
}
