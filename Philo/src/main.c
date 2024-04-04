/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 10:52:49 by codespace         #+#    #+#             */
/*   Updated: 2024/04/04 14:15:20 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../inc/philosophers.h"
#include "../inc/errors.h"
#include "../inc/colors.h"

void help(char *error)
{
    printf("%s%s%s\n\n", BRED, error, RES);
    printf("\t%sUsage: ./philo <n_philos> <time_to_die> <time_to_eat> <time_to_sleep>\n", BMAG);
    printf("<time_to_sleep> [n_times_each_philospher_eat]\n");
}
    


int main(int argc, char **argv)
{
    t_table table;

    if (argc != 5 && argc != 6)
        return (help(ARGC_ERROR), EXIT_FAILURE);
    if (args_parsing(&table, argv))
        return (EXIT_FAILURE);
    if (data_init(&table))
        return(EXIT_FAILURE);
    // // // print_info(table);
    // if(start_simulation(&table))
    // //     return(EXIT_FAILURE);
    // safe_exit(&table);
    return(EXIT_SUCCESS);
}

