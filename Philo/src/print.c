/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbonilla <dbonilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 07:02:00 by codespace         #+#    #+#             */
/*   Updated: 2024/04/08 18:20:22 by dbonilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"
#include "../inc/colors.h"


void help(char *error)
{
    printf("%s%s%s\n", BRED, error, RES);
    printf("%sUsage: ./philo <n_philos> <time_to_die> <time_to_eat> <time_to_sleep> ", BMAG);
    printf("<time_to_sleep> [n_times_each_philospher_eat]\n");
}


void print_action(t_action action, t_table *table,t_philo philo)
{
    size_t start_time;
    start_time = table->start_time;
    pthread_mutex_lock(&table->write_mtx);
    if(action == DEAD && is_simulation_finish(table) == true)
        printf("%-6zu %d died \n", get_time(MILISECONDS) - start_time , philo.id);
    if (action == EATING && is_simulation_finish(table) != false)
        printf("%-6zu %d is Eating\n", get_time(MILISECONDS) - start_time, philo.id);
    if (action == TAKING_A_FIRST_FORK && is_simulation_finish(table) != false)
        printf("%-6zu %d has taken the first fork\n", get_time(MILISECONDS) - start_time, philo.id);
    if (action == TAKING_A_SECOND_FORK && is_simulation_finish(table) !=  false)
        printf("%-6zu %d has taken the second fork\n", get_time(MILISECONDS) - start_time, philo.id);
    if(action == SLEEPING && is_simulation_finish(table) != false)
        printf("%-6zu %d is Sleeping \n", get_time(MILISECONDS) - start_time,philo.id);
    if(action == THINKING && is_simulation_finish(table) != false)
        printf("%-6zu %d is Thinking \n", get_time(MILISECONDS) - start_time, philo.id);    
    pthread_mutex_unlock(&table->write_mtx);
}