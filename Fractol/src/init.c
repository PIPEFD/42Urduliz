/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: event <event@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 16:21:01 by event             #+#    #+#             */
/*   Updated: 2024/03/04 16:53:52 by event            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"



static void	data_init(t_fractal *fractal)
{
	fractal->escape_valeu = 4;
	fractal->iterations_defintion = 1000;
	fractal->axle_x = 0.0;
	fractal->axle_y = 0.0;
	fractal->zoom = 1.0;
}

int fractal_init(t_fractal *fractal)
{
	fractal->mlx_main_screen = mlx_init(WIDTH, HEIGHT, \
										fractal->name_fractal);
	if (NULL == fractal->mlx_main_screen)
	{
		// puts(mlx_strerror(mlx_errno));
		return (EXIT_FAILURE);
	}
	fractal->mlx_fractal_screen = mlx_new_image(fractal->mlx_main_screen, \
										WIDTH, HEIGHT);
	if (NULL == fractal->mlx_fractal_screen)
	{
		mlx_close_window(fractal->mlx_main_screen);
		// puts(mlx_strerror(mlx_errno));
		return (EXIT_FAILURE);
	}
	data_init(fractal);
	return (EXIT_SUCCESS);
}
