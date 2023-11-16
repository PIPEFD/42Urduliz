/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlst_last.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 16:32:40 by codespace         #+#    #+#             */
/*   Updated: 2023/11/03 16:35:08 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include ""

t_intlst *ft_intlst_last(t_intlst *lst)
{
    if (lst == NULL)
        return (NULL);
    while (lst -> next)
        lst = lst->next;
    return (lst);
}