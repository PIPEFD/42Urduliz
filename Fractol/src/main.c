/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: event <event@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 08:10:55 by codespace         #+#    #+#             */
/*   Updated: 2024/03/04 17:14:11 by event            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int	ft_strncmp( const char *s1, const char *s2, size_t n)
{
	unsigned int	i;
	unsigned char	*z1;
	unsigned char	*z2;

	z1 = (unsigned char *)s1;
	z2 = (unsigned char *)s2;
	i = 0;
	while (z1[i] != '\0' && z2[i] != '\0' && i < n)
	{
		if (z1[i] != z2[i])
			return (z1[i] - z2[i]);
		i++;
	}
	if (i < n)
	{
		return (z1[i] - z2[i]);
	}
	return (0);
}


int main()
{
    void *mlx_ptr = mlx_init();
    void *win_ptr = mlx_new_window(mlx_ptr, WIDTH, HEIGHT, "Mandelbrot Set");

    draw_mandelbrot(mlx_ptr, win_ptr);

    mlx_loop(mlx_ptr);

    return 0;
}

// int  main(int argc, char **argv)
// {
//     t_fractal fractal;

//     if ((2 == argc && !ft_strncmp(argv[1], "Mandelbrot", 10)) \
//     || (4 == argc && !ft_strncmp(argv[1], "Julia", 5)))
//     {
//         fractal.name_fractal = argv[1];
//         // if (!ft_strncmp(argv[1], "Julia", 5));
//         // {
//         //     fractal.julia_y = ft_atoidbl(argv[2]); 
//         //     fractal.julia_x = ft_atoidbl(argv[3]); 
//         // }
//         // fractal_init(&fractal);

//         // return (EXIT_FAILURE);
//         void *mlx_ptr = mlx_init();
//         void *win_ptr = mlx_new_window(mlx_ptr, WIDTH, HEIGHT, "Mandelbrot Set");
//         draw_mandelbrot(mlx_ptr, win_ptr);
//         // mlx_loop (fractal.mlx_main_screen);
//         mlx_loop(draw_mandelbrot(mlx_ptr);
        
//     }
// 	// else
// 	// {
// 	// 	ft_putstr_fd(ERROR_MESSAGE, STDERR_FILENO);
// 	// 	return (EXIT_FAILURE);
// 	// }
// }
