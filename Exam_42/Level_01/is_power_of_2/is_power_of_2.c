/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_power_of_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 14:03:36 by codespace         #+#    #+#             */
/*   Updated: 2024/07/15 13:44:15 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int is_power_of_2(unsigned int n)
{
    if (n <= 0)
        return(0);
    while (n != 1)
    {
        if (n % 2 != 0)
            return(0);
        n /= 2;
    }
    return(1);
        
}

int main(void)
{
    int nbr = 1023;
    
    if (is_power_of_2(nbr))
        printf("%u is power of 2", nbr);
    else
        printf("%u not is power of 2", nbr);
    return(0);
}
