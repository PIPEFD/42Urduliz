/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlst_issorted.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 14:43:25 by codespace         #+#    #+#             */
/*   Updated: 2023/11/07 14:51:45 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include ""


int ft_intlst_issorted(t_intlst *lst)
{
    while (lst->next)
    {
        if (lst->value >lst->next->value)
            return (0);
        lst = lst->next;
    }
    return (1);
}