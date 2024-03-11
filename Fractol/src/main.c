/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipefd <pipefd@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 08:10:55 by codespace         #+#    #+#             */
/*   Updated: 2024/03/07 21:01:14 by pipefd           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

// int main(int ac, char **av)
// {
//     t_fractal fractal;

//     if ((2 == ac && !ft_strncmp(av[1], "mandelbrot", 10)) ||
//         (4 == ac && !ft_strncmp(av[1], "julia", 5)))
//     {
//         fractal.name = av[1];
//         fractal_init(&fractal);
//         fractal_render(&fractal);
//         mlx_loop(fractal.mlx_connection);
//     }
//     else
//     {
//         ft_putstr_fd(MSG_ERR, STDERR_FILENO);
//         return (EXIT_FAILURE);
//     }
// }





int main()
{
    t_fractal fractal;

    // fractal.name = av[1];
    fractal_init(&fractal);
    fractal_render(&fractal);
    mlx_loop(fractal.mlx_connection);

    return 0;
}

        // fractal_init(&fractal);
        // fractal_render(&fractal);
        // mlx_loop(fractal.mlx_connection);
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