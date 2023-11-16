/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlst_before last.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 12:56:55 by codespace         #+#    #+#             */
/*   Updated: 2023/10/24 19:40:39 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "../../inc/libft.h"

t_intlst *ft_intlst_before_last(t_intlst *lst)
{
    if(lst == NULL)
        return (NULL);
    while (lst->next->next)
        lst = lst->next;
    return(lst);
}