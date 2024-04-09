/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbonilla <dbonilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 10:52:49 by codespace         #+#    #+#             */
/*   Updated: 2024/04/09 15:08:58 by dbonilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../inc/philosophers.h"
#include "../inc/errors.h"
#include "../inc/colors.h"


// int is_zero(char **argv)
// {
//     int i;

//     i = 1;
//     while (argv[i][0] != '-' && argv[i + 1][0])
//     {
//         if (argv[i][0] == '0')
//             return (1);
//         i++;        
//         write(1, "is_zero\n", 8);
//     }
//     return (0);
// }
    
// if (is_zero(argv) == 1)
//     return (help(ARGC_ERROR),EXIT_FAILURE);


int main(int argc, char **argv)
{
    t_table table;

    if (argc != 5 && argc != 6)
        return (help(ARGC_ERROR), EXIT_FAILURE);
    if (args_parsing(&table, argv))
        return (EXIT_FAILURE);
    if (table.n_philos <= 1) 
        return (1);
    if (data_init(&table))
        return(EXIT_FAILURE);
    print_info(table);
    if(start_simulation(&table))
        return(EXIT_FAILURE);
    safe_exit(&table);
    return(EXIT_SUCCESS);
}

