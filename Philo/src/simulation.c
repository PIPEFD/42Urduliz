/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbonilla <dbonilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 01:36:05 by codespace         #+#    #+#             */
/*   Updated: 2024/04/09 22:18:02 by dbonilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"
#include "../inc/errors.h"
#include "../inc/colors.h"


void *philo_routine(void *data)
{
    t_philo *philo;
    philo = (t_philo *)data;
        while (!all_philos_running(&philo->table->control_mtx,
			&philo->table->n_philos_running, philo->table->n_philos))  
        ;
    //philo->last_meal_time = get_time(MILISECONDS);
    if (philo->table->n_philos == 1)
        usleep_mod(philo->table->time_die * 1e3, philo->table);
    if (philo->id % 2)
        usleep_mod(philo->table->time_sleep * 1000 / 2, philo->table);     
    set_long(&philo->philo_mtx, &philo->last_meal_time, philo->table->start_time);
    while (!is_simulation_finish(philo->table))
    {
    //printf("philo routine %i\n", philo->id);
        eating(philo);
        if (philo->table->full_philos == philo->table->n_philos)
            break;
        print_action(SLEEPING, philo->table, *philo);
        usleep_mod(philo->table->time_sleep * 1e3, philo->table);
        print_action(THINKING, philo->table, *philo);
        thinking(philo);
    }
    return (NULL);
}
       
static void *supervisor_routine(void *data)
{
    t_table     *table;
    unsigned int    i;
 //   char c;
    
    table = (t_table *)data;
    while (!all_philos_running(&table->control_mtx,
			&table->n_philos_running, table->n_philos))  
        ;
    usleep_mod(table->time_die * 1e3, table);
    while (!is_simulation_finish(table))
    {

        i =-1;
        while (++i < table->n_philos && !is_simulation_finish(table))
        {
            if (is_dead(&table->philos[i]) == true)
            {      
                print_action(DEAD, table, table->philos[i]);
                set_bool(&table->control_mtx, &table->end_sim, true);
            }
        }
    }
    return (NULL);
}

int start_simulation(t_table *table)
{
    unsigned int i;

    i = 0;
    if (pthread_create(&table->supervisor, NULL, supervisor_routine, table))
            return(printf("%s"THREAD_ERROR"%s\n", RED, RES), 1);
    while (i < table->n_philos)
    {
        if(pthread_create(&table->philos[i].thread_id, NULL, philo_routine, \
                                                        &table->philos[i]))
            return(printf("%s"THREAD_ERROR"%s\n", RED, RES), 1);
        i++;
    }
    set_long(&table->table_mtx, &table->start_time, get_time(MILISECONDS));
    set_long(&table->table_mtx, &table->n_philos_running, table->n_philos);
    set_bool(&table->table_mtx, &table->start_sim, true);
    i = -1;
    while(++i < table->n_philos)
        pthread_join(table->philos[i].thread_id, NULL);
    set_bool(&table->table_mtx, &table->end_sim, true);
    pthread_join(table->supervisor, NULL);
    return(0);
}

