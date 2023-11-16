/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlst_new.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 16:15:36 by codespace         #+#    #+#             */
/*   Updated: 2023/11/03 16:23:50 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include ""

t_intlst *ft_intlst_new(int value)
{
    t_intlst *new;

    new = (t_intlst *)malloc(sizeof(t_intlst));
    if (new == NULL)
       return(NULL);
    new->value = value;
    new->next= NULL;
    return (new);
}
