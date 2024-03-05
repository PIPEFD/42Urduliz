/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 21:13:34 by codespace         #+#    #+#             */
/*   Updated: 2024/02/26 13:35:59 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"
#include "../inc/error.h"


int main(int argc, char **argv)
{
    t_table table;

    if (argc != 5 && argc != 6)
        return (help(ARGC_ERROR), EXIT_FAILURE);
    if (args_parsing(&table, argv))
        return (EXIT_FAILURE);
    if (init_data(&table))
        return(EXIT_FAILURE);
    print_info(table);
    if(start_simulation(&table))
        return(EXIT_FAILURE);
    // safe_exit(&table);
    return(EXIT_SUCCESS);
}

