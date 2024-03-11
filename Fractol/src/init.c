/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 16:21:01 by event             #+#    #+#             */
/*   Updated: 2024/03/09 23:07:20 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

static void malloc_error()
{
	perror(MSG_ERR);
	exit(EXIT_FAILURE);
}

static void	data_init(t_fractal *fractal)
{
	fractal->hypo_value  = 4;
	fractal->interations = 1000;
}

// static void	data_init(t_fractal *fractal)
// {
// 	fractal->escape_valeu = 4;
// 	fractal->iterations_defintion = 1000;
// 	fractal->axle_x = 0.0;
// 	fractal->axle_y = 0.0;
// 	fractal->zoom = 1.0;
// }

void fractal_init(t_fractal *fractal)
{
	fractal->mlx_connection = mlx_init();
	if (NULL == fractal->mlx_connection)
		malloc_error();
	fractal->mlx_window = mlx_new_window(fractal->mlx_connection,
										WIDTH,
										HEIGHT,
										WIN_TITLE);
	if (NULL == fractal->mlx_window)
	{
		// mlx_destroy_display(fractal->mlx_connection);
		free (fractal->mlx_connection);
		malloc_error();
		
	}
	fractal->img.img_ptr = mlx_new_image(fractal->mlx_connection,
										WIDTH, HEIGHT);
	if (NULL == fractal->img.img_ptr)
	{
		mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
		// mlx_destroy_display(fractal->mlx_connection);
		free (fractal->mlx_connection);
		malloc_error();
		
	}	
	fractal->img.pixels_ptr = mlx_get_data_addr(fractal->img.img_ptr, 
										&fractal->img.bpp, 
										&fractal->img.line_len,
										&fractal->img.endian);
	// events_init(fractal);
	data_init(fractal);
	// return (EXIT_SUCCESS);
	
}

