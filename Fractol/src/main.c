/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 08:10:55 by codespace         #+#    #+#             */
/*   Updated: 2024/03/04 21:25:29 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"


// int main()
// {
//     void *mlx_ptr = mlx_init();
//     void *win_ptr = mlx_new_window(mlx_ptr, WIDTH, HEIGHT, "Mandelbrot Set");

//     draw_mandelbrot(mlx_ptr, win_ptr);

//     mlx_loop(mlx_ptr);

//     return 0;
// }

int  main(int argc, char **argv)
{
    t_fractal fractal;

    if ((2 == argc && !ft_strncmp(argv[1], "Mandelbrot", 10)) \
    || (4 == argc && !ft_strncmp(argv[1], "Julia", 5)))
    {
        fractal_init(&fractal);
        fractal_render(&fractal);
        mlx_loop(fractal.mlx_connection);
        // fractal.name_fractal = argv[1];
        // if (!ft_strncmp(argv[1], "Julia", 5));
        // {
        //     fractal.julia_y = ft_atoidbl(argv[2]); 
        //     fractal.julia_x = ft_atoidbl(argv[3]); 
        // }

        // return (EXIT_FAILURE);
        // void *mlx_ptr = mlx_init();
        // void *win_ptr = mlx_new_window(mlx_ptr, WIDTH, HEIGHT, "Mandelbrot Set");
        // draw_mandelbrot(mlx_ptr, win_ptr);
        // // mlx_loop (fractal.mlx_main_screen);
        
    }
	else
	{
		ft_putstr_fd(ERROR_MESSAGE, STDERR_FILENO);
		return (EXIT_FAILURE);
	}
}
