/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   koch.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 20:37:16 by dbonilla          #+#    #+#             */
/*   Updated: 2023/12/22 08:15:09 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"


void draw_koch_curve(void *mlx_ptr, void *win_ptr, t_point start, t_point end, int depth)
{
    if (depth == 0)
    {
        draw_line(mlx_ptr, win_ptr, start, end);
    }
    else
    {
        t_point p1 = {start.x + (end.x - start.x) / 3, start.y + (end.y - start.y) / 3};
        t_point p2 = {
            (int)(start.x + 0.5 * (end.x - start.x) + fast_inverse_sqrt(3) * (end.y - start.y) / 6),
            (int)(start.y + 0.5 * (end.y - start.y) - fast_inverse_sqrt(3) * (end.x - start.x) / 6)};
        t_point p3 = {start.x + 2 * (end.x - start.x) / 3, start.y + 2 * (end.y - start.y) / 3};

        draw_koch_curve(mlx_ptr, win_ptr, start, p1, depth - 1);
        draw_koch_curve(mlx_ptr, win_ptr, p1, p2, depth - 1);
        draw_koch_curve(mlx_ptr, win_ptr, p2, p3, depth - 1);
        draw_koch_curve(mlx_ptr, win_ptr, p3, end, depth - 1);
    }
}
