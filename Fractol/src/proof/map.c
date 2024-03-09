/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipefd <pipefd@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 22:43:11 by pipefd            #+#    #+#             */
/*   Updated: 2024/03/07 16:47:54 by pipefd           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdio.h"


double map(double unscaled_num, double new_min, double new_max, double old_min, double old_max)
{
    return (new_max - new_min) * (unscaled_num - old_min) / (old_max - old_min) + new_min;
}

// int main()
// {
//     for (int i = 0; i < 42; ++i)
//     {
//         printf("%d -> %f\n", i, map((double)i, -2, +2, 0, 700));
//     }
// }