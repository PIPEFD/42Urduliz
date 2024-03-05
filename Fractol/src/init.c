/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 16:21:01 by event             #+#    #+#             */
/*   Updated: 2024/03/04 23:26:56 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

static void malloc_error()
{
	ft_putstr_fd(MSG_ERR, 2); s;
	exit(EXIT_FAILURE);
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
	fractal->mlx_window = mlx_new_window(fractal->mlx_connection, mlx_ptr:
										WIDTH, size_x:
										HEIGHT, size_y:
										fractal->name); title:
	if (NULL == fractal->mlx_window)
	{
		mlx_destroy_image(fractal->mlx_connection);mlx_ptr:
		free(fractal->mlx_connection); mlx_ptr:
		free (fractal->mlx_connection); ptr;
		malloc_error();
		
	}
	fractal->img.img_ptr = mlx_new_image(fractal->img.img_ptr, img_ptr:
										&fractal->img.bpp, bits_per_pixel:
										&fractal->img.line_len, size_line:
										&fractal->img.endian); endian:
	data_init(fractal);
	return (EXIT_SUCCESS);
}
