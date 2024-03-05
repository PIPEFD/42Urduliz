/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 18:20:05 by codespace         #+#    #+#             */
/*   Updated: 2024/02/26 18:07:08 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"
#include "../inc/error.h"
#include "../inc/colors.h"

void help(char *error)
{
    printf("%s%s%s\n\n", BRED, error, RES);
    printf("\t%sUsage: ./philo <n_philos> <time_to_die> <time_to_eat>", BMAG);
    printf("<time_to_sleep> [n_times_each_philospher_eat]\n");
    printf("\t <> --> Obligatory \n\t[] --> optional\n\n%s ", RES);
}

void print_info(t_table table)
{
    printf("\n%s----------> INPUT <--------\n|\n", BBLU);
    printf("|--> %s Total Philos = %zu philos%s\n", \
                                GRN, table.n_philos, BBLU);
    printf("|--> %s Time To die = %zu philos%s\n", \
                                GRN, table.time_die, BBLU);
    printf("|--> %s Time To eat = %zu philos%s\n", \
                                GRN, table.time_eat, BBLU);
    printf("|--> %s Time To sleep = %zu philos%s\n", \
                                GRN, table.time_sleep, BBLU);
    if(table.n_time_eat == -1)
        printf ("|--> %sNumber Meals = not_specified%s\n",MAG, BBLU);
    else
        printf ("|--> %sNumber Meals = %zu meals%s\n", \
                                        MAG, table.n_time_eat, BBLU);
    printf("\n\n        %s-- %s STARTING SIMULATION %s %s\n\n", \
                                                        BGRN, GRN, BGRN, RES);
}

void    print_action(t_action action, t_table *table, t_philo philo)
{
    size_t start_time;
    
    start_time = table->start_time;
    pthread_mutex_lock(&table->write_mtx);
    if(action == DEAD && is_simulation_finish(table) == false)
        printf("%-6zu %d died \n", get_time(MILISECONDS) - start_time , philo.id);
    else if(action == EATING && is_simulation_finish(table) == false)
        printf("%-6zu %d is Eating \n", get_time(MILISECONDS) - start_time, \
                                                                    philo.id);
    else if(action == SLEEPING && is_simulation_finish(table) == false)
        printf("%-6zu %d is Sleeping \n", get_time(MILISECONDS) - start_time, \
                                                                    philo.id);
    else if(action == THINKING && is_simulation_finish(table) == false)
        printf("%-6zu %d is Thinking \n", get_time(MILISECONDS) - start_time, \
                                                                    philo.id);
    else if(action == TAKING_A_FORK && is_simulation_finish(table) == false)
        printf("%-6zu %d has taken a fork \n", \
                            get_time(MILISECONDS) - start_time, philo.id);
    pthread_mutex_lock(&table->write_mtx);
}