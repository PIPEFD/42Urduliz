/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 22:45:29 by codespace         #+#    #+#             */
/*   Updated: 2023/11/03 10:01:04 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include ""

static int ft_input_size(int argc, char ***argv)
{
    int size;
    int i;

    i = 0;
    size = 0;
    while (i < argc)
        size += ft_strlen(*(*(argv)+ i++)) + 1;
    return (size);
}


static int ft_argcount(char **tab)
{
    int i;

    i = 0;
    while (*(tab + i))
        i++;
    return (i);
}

int ft_input_to_args(int argc, char ***argv)
{
    char    *string;
    char    **arg_list;
    int     i;
    int     flag;

    string = (char *)malloc(sizeof(char) * (ft_input_size(argc, argv) + 1));
    if (!string)
        return (0);
    i = 0;
    flag = 1;
    while (i < argc)
    {
        if (flag == 0)
        {
            
            string = ft_strcat(string, " ");
            flag = 1;
            continue;
        }
        string = ft_strcat(string, *(*(argv) + i++));
        flag = 0;
    }
    arg_list = ft_split(string, ' ');
    free (string);
    *argv = arg_list;
    return (ft_arcount(arg_list));
    
}
