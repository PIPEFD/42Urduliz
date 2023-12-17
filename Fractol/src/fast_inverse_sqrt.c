/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fast_inverse_sqrt.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbonilla <dbonilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 17:41:25 by dbonilla          #+#    #+#             */
/*   Updated: 2023/12/17 20:34:44 by dbonilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

float fast_inverse_sqrt(float x)
{
    float xhalf = 0.5f * x;
    int i = *(int *)&x;        // interpret float as int
    i = 0x5f3759df - (i >> 1); // initial guess for Newton's method
    x = *(float *)&i;          // convert new bits into float
    x = x * (1.5f - xhalf * x * x); // One round of Newton's method
    return x;
}
