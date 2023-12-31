/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_samesign.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 17:01:26 by codespace         #+#    #+#             */
/*   Updated: 2023/10/03 18:39:53 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

int ft_is_samesign(int a, int b)
{
    if((a >= 0 && b >= 0) || (a < 0 && b < 0))
        return(1);
    return(0);
}