/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 16:21:01 by event             #+#    #+#             */
/*   Updated: 2024/04/16 22:02:12 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

static void	malloc_error(void)
{
	ft_putstr_fd(MSG_ERR, STDERR_FILENO);
	exit(EXIT_FAILURE);
}

void	events_init(t_fractal *fractal)
{
	mlx_do_key_autorepeaton(fractal->mlx_window);
	mlx_hook(fractal->mlx_window, 2, 0, deal_keyboard, fractal);
	mlx_mouse_hook(fractal->mlx_window, &mouse_hook, fractal);
	mlx_hook(fractal->mlx_window, 17, 1L << 17, &close_handler, fractal);
	mlx_loop(fractal->mlx_connection);
}
void	data_init(t_fractal *fractal)
{
	fractal->hypo_value = 4;
	fractal->interations = 42;
	fractal->move.zoom = 0.5;
	fractal->move.x_ran = 0.0;
	fractal->move.y_ran = 0.0;
}

inline void	fractal_init(t_fractal *fractal)
{
	fractal->mlx_connection = mlx_init();
	if (NULL == fractal->mlx_connection)
		malloc_error();
	fractal->mlx_window = mlx_new_window(fractal->mlx_connection, \
										WIDTH, \
										HEIGHT, \
										WIN_TITLE);
	fractal->img.img_ptr = mlx_new_image(fractal->mlx_connection, \
										WIDTH, HEIGHT);
	fractal->img.pixels_ptr = mlx_get_data_addr(fractal->img.img_ptr, \
											&fractal->img.bpp, \
											&fractal->img.line_len, \
											&fractal->img.endian);
	data_init(fractal);
	events_init(fractal);
}
