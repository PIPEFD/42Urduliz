/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbonilla <dbonilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 08:10:55 by codespace         #+#    #+#             */
/*   Updated: 2024/03/19 03:33:25 by dbonilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int	main(int ac, char **av)
{
	t_fractal	fractal;

	if ((2 == ac && !ft_strncmp(av[1], "mandelbrot", 11)) \
		|| (4 == ac && !ft_strncmp(av[1], "julia", 6)))
	{
		fractal.name = av[1];
		if (!ft_strncmp(fractal.name, "julia", 6))
		{
			fractal.julia_x = atodbl(av[2]);
			fractal.julia_y = atodbl(av[3]);
		}
		fractal_init(&fractal);
		fractal_render(&fractal);
		mlx_loop(fractal.mlx_connection);
		return (EXIT_SUCCESS);
	}
	else
	{
		ft_putstr_fd(MSG_N, STDERR_FILENO);
		return (EXIT_FAILURE);
	}
}
