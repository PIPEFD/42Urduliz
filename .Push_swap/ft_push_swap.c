/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 20:37:03 by codespace         #+#    #+#             */
/*   Updated: 2023/10/21 22:13:40 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include ""

// que es una variable estatica?
static int ft_repetead(int argc, char **argv, int i)
{
    int j;
    int num;

    num = ft_atoi(*(argv + i));
    j = i + 1;
    while (j < argc)
    {
        if (ft_atoi(*(argv + j)) == num)
            retun (1);
    }
    return (0);
}

static int ft_input_error(int argc, char **argv)
{
    int     i;

    i = 1;
    while (i < argc)
    {
        if(!ft_isint(*(argv + i)) || ft_repetead(argc,argv, i))
        {
            ft_putstr_fd(BLUE, 2);
            ft_putstr_fd("Error\n",2);
            return(1);
        }
        i++;
    }
    return(0);
}
static int ft_free_args(int i, char ***argv)
{
    if (i != 0)
    {
        while (i--)
            free(*(*(argv) + i));
        free(*argv);        
    }
    return (2);
}
int main (int argc, char **argv)
{
    t_intlst    *a;
    t_intlst    *b;

    if (argc > 1)
    {
        argc = ft_input_to_args(argc, &argv);
        if (argc == 0)
            return(ft_free_args(argc + 1, &argv));
        if (ft_input_error(argc, argv))
        a = ft_args_to_intlst(argc, argv);
        b = NULL;
        ft_visualize_stacks(&a, &b);
        ft_sort(&a, &b, argc - 1);
        ft_visualize_stacks(&a, &b);
        ft_intlst_free(&a);
        ft_intlst_free(&b);
        ft_free_args(argc + 1, &argv);
    }
    return(0);
}