/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 08:10:55 by codespace         #+#    #+#             */
/*   Updated: 2024/02/29 08:11:33 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int main()
{
    void *mlx_ptr = mlx_init();
    void *win_ptr = mlx_new_window(mlx_ptr, WIDTH, HEIGHT, "Mandelbrot Set");

    draw_mandelbrot(mlx_ptr, win_ptr);

    mlx_loop(mlx_ptr);

    return 0;
}