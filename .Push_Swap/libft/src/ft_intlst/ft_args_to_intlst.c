/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_args_to_intlst.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 10:20:36 by codespace         #+#    #+#             */
/*   Updated: 2023/11/03 10:32:47 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include " "

t_intlst *ft_args_to_intlst(int argc, char **argv)
{
    int i;
    t_intlst    *a;
    t_intlst    *temp;

    i = 1;
    while (i < argc)
    {
        if (i == 1)
            a = ft_intlst_new(ft_atoi((*(argv + i))));
        else
        {
            temp = ft_intlst_new(ft_atoi((*(argv + i))));
            ft_intlst_addback(&a, temp);
        }
        i++;
    }
    return (a);
}
