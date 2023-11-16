/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlst_addback.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 16:25:00 by codespace         #+#    #+#             */
/*   Updated: 2023/11/03 16:29:37 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include ""

void ft_intlst_addback(t_intlst **lst, t_intlst * new)
{
    t_intlst *tmp;

    if (new && *lst)
    {
        if (*lst == NULL)
            *lst = new;
        else
        {
            tmp = ft_intlst_last(*lst);
            tmp->next = new;
        }
    }
    
}