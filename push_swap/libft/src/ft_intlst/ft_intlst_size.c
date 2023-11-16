/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlst_size.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 14:24:02 by codespace         #+#    #+#             */
/*   Updated: 2023/10/24 19:40:59 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"


size_t ft_intlst_size(t_intlst *lst)
{
    unsigned int    size;

    size = 0;
    while(lst)
    {
        size++;
        lst = lst->next;
    }
    return(size);
}