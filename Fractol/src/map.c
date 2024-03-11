/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipefd <pipefd@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 22:43:11 by pipefd            #+#    #+#             */
/*   Updated: 2024/03/07 21:20:35 by pipefd           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

double scale(double unscaled_num, double new_min, double new_max, double old_max)
{
    return ((new_max - new_min) * (unscaled_num - 0) / (old_max - 0) + new_min);
}


t_complex sum_complex(t_complex z1, t_complex z2)
{
    t_complex   result;

    result.x = z1.x + z2.x;
    result.y = z1.x + z2.y;
    return (result);
}

t_complex square(t_complex z)
{
  t_complex result;

  result.x = (z.x * z.x) - (z.y * z.y);
  result.y = 2 * z.x * z.y;   
  return result;
}
// int main()
// {
//     for (int i = 0; i < 42; ++i)
//     {
//         printf("%d -> %f\n", i, scale((double)i, -2, +2, 0, 700));
//     }
// }