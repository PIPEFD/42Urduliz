/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbonilla <dbonilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 07:02:00 by codespace         #+#    #+#             */
/*   Updated: 2024/04/09 22:23:13 by dbonilla         ###   ########.fr       */
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
void	print_info()
{
	// printf("\n%s********************* INPUT *********************\n|\n", BBLU);
	// printf("|-->  %stotal Philos 🧙   =  %zu philos%s\n", \
	// 								GRN, table.n_philos, BBLU);
	// printf("|-->  %stime to die 💀    =  %zu ms%s\n", \
	// 								RED, table.time_die, BBLU);
	// printf("|-->  %stime to eat 🍝    =  %zu ms%s\n", \
	// 								YEL, table.time_eat, BBLU);
	// printf("|-->  %stime to sleep 😴  =  %zu ms%s\n", \
	// 								CYN, table.time_sleep, BBLU);
	// if (table.n_time_eat == -1)
	// 	printf("|-->  %snumber meals 🥣   =  not specified%s\n", MAG, BBLU);
	// else
	// 	printf("|-->  %snumber meals 🥣   =  %zu meals%s\n", \
	// 								MAG, table.n_time_eat, BBLU);
	printf("\n\n           %s-- %s STARTING SIMULATION %s%s --%s\n\n", \
									BGRN, GRNB, RES, BGRN, RES);
}

void print_action(t_action action, t_table *table,t_philo philo)
{
    size_t start_time;
    start_time = table->start_time;
    printf("start->time %zu\n", start_time);
    printf("time %zu\n", get_time(MILISECONDS));
    printf("diferencia de tiempo  %zu\n", get_time(MICROSECONDS) - start_time);
    pthread_mutex_lock(&table->write_mtx);
    if(action == DEAD && is_simulation_finish(table) == false)
        printf("%-6zu %d died \n", get_time(MILISECONDS) - start_time , philo.id);
    else if (action == EATING && is_simulation_finish(table) == false)
        printf("%-6zu %d is Eating\n", get_time(MILISECONDS) - start_time, philo.id);
    else if (action == TAKING_A_FIRST_FORK && is_simulation_finish(table) == false)
        printf("%-6zu %d has taken the first fork\n", get_time(MILISECONDS) - start_time, philo.id);
    else if (action == TAKING_A_SECOND_FORK && is_simulation_finish(table) ==  false)
        printf("%-6zu %d has taken the second fork\n", get_time(MILISECONDS) - start_time, philo.id);
    else if(action == SLEEPING && is_simulation_finish(table) == false)
        printf("%-6zu %d is Sleeping \n", get_time(MILISECONDS) - start_time,philo.id);
    else if(action == THINKING && is_simulation_finish(table) == false)
        printf("%-6zu %d is Thinking \n", get_time(MILISECONDS) - start_time, philo.id);    
    pthread_mutex_unlock(&table->write_mtx);
}