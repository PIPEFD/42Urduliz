/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 13:36:24 by codespace         #+#    #+#             */
/*   Updated: 2024/03/28 18:41:48 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"
#include "../inc/error.h"
#include "../inc/colors.h" //Make test//

static void *one_philo_routine(t_philo *philo)
{
    print_action(TAKING_A_FORK, philo->table, *philo);
    while (is_simulation_finish(philo->table) == false)
        ;
    return (NULL);
}

static void  *philo_routine(void *data)
{
    t_philo *philo;

    philo = (t_philo *)data;
    wait_all_threads(philo->table);
    philo->last_meal_time = get_time(MILISECONDS);
    increment_n_philos(philo->table);
    if (philo->table->n_philos == 1)
        return (one_philo_routine(philo));
    make_simulation_fair(philo);
    while (is_simulation_finish(philo->table) == false)
    {
        eating(philo);
        if (philo->is_full == true)
            break;
        print_action(SLEEPING, philo->table, *philo);
        unsleep_mod(philo->table->time_sleep * 1e3, philo->table);
        thinking(philo);
    }
    return (NULL);
}

static void *supervisor_routine(void *data)
{
    t_table     *table;
    unsigned int    i;
    
    table = (t_table *)data;
    while (all_philos_running(&table->control_mtx, table) == false)
        ;
    while (is_simulation_finish(table) == false)
    {
        i =-1;
        while (++i < table->n_philos && is_simulation_finish(table) == false)
        {
            if(is_dead(&table->philos[i] == true));
            {
                print_action(DEAD, table->philos[i]);
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
        return(printf("%s"THREAD_ERROR"%s\n"), RED, RES, 1);
    while (i < table->n_philos)
    {
        if(pthread_create(&table->philos[i].thread_id, NULL, philo_routine, \
                                                        &table->philos[i]));
            return(printf("%s"THREAD_ERROR"%s\n", RED, RES), 1);
        i++;
    }
    table->start_time = get_time(MILISECONDS);
    set_bool(&table->control_mtx, &table->start_sim, true);
    i = -1;
    while(++i < table->n_philos)
        pthread_join(table->philos[i].thread_id, NULL);
    set_bool(&table->control_mtx, &table->end_sim, true);
    pthread_join(table->supervisor, NULL);
    return(0);
} 