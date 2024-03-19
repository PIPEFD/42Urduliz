/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbonilla <dbonilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 16:51:44 by event             #+#    #+#             */
/*   Updated: 2024/03/19 02:13:24 by dbonilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"
#include "keycode_mac.h"

int	close_handler(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx_connection, fractal->img.img_ptr);
	mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
	free(fractal->mlx_connection);
	exit(EXIT_SUCCESS);
}

inline int	deal_keyboard(int key_code, t_fractal *fractal)
{
	if (key_code == KEY_ESCAPE)
		close_handler(fractal);
	else if (key_code == KEY_D)
		fractal->move.x_ran += (fractal->move.zoom * 0.5);
	else if (key_code == KEY_A)
		fractal->move.x_ran -= (fractal->move.zoom * 0.5);
	else if (key_code == KEY_S)
		fractal->move.y_ran -= (fractal->move.zoom * 0.5);
	else if (key_code == KEY_W)
		fractal->move.y_ran += (fractal->move.zoom * 0.5);
	else if (key_code == KEY_PAD_ADD)
		fractal->interations += 10;
	else if (key_code == KEY_PAD_SUB)
		fractal->interations -= 10;
	fractal_render(fractal);
	return (0);
}
