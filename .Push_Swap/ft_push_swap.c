/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 22:14:47 by codespace         #+#    #+#             */
/*   Updated: 2023/11/07 16:15:22 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include ""


int main (int argc, char **argv)
{
    t_intlst    *a;
    t_intlst    *b;

    if (argc > 1)
    {
        argc = ft_input_to_args(argc,&argv);
        if (argc == 0)
            return(ft_free_args(argc + 1, &argv));
        if (ft_input_error(argc, argv))
            return (ft_free_args(argc,argv));
        a = ft_args_to_intlst(argc, argv);
        b = NULL;
        ft_visualize_stacks(&a, &b);
        ft_sort(&a, &b, argc - 1);
        
    }
}