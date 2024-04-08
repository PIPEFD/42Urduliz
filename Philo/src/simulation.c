/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbonilla <dbonilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 01:36:05 by codespace         #+#    #+#             */
/*   Updated: 2024/04/08 21:55:42 by dbonilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"
#include "../inc/errors.h"
#include "../inc/colors.h"
#include <stdio.h>
#include <unistd.h>

void *philo_routine(void *data)
{
    t_philo *philo;
    philo = (t_philo *)data;
    wait_all_threads(philo->table);
    philo->last_meal_time = get_time(MILISECONDS);
    increment_n_philos(philo->table);
    simulation_fair(philo); 
  while (is_simulation_finish(philo->table) || philo->table->start_sim != true)
    {
     
        eating(philo);
        if (philo->is_full == true)
            break;
        print_action(SLEEPING, philo->table, *philo);
        usleep_mod(philo->table->time_sleep * 1e3, philo->table);
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
    // printf("supervisor paso 1 \n");
    while (!all_philos_running(&table->control_mtx, table))
    
        // printf("supervisor paso while\n");
        // printf("result %d \n", all_philos_running(&table->control_mtx, table));
//        read(1, &c, 1);
        ;
    // printf("supervisor paso 2\n");
    // printf("final simulación %i\n", is_simulation_finish(table));
    while (!is_simulation_finish(table))
    {
        i =-1;
        // printf("routine antes\n");
        // printf("philos %li \t simulación %i\n", table->n_philos, is_simulation_finish(table));
        while (++i <= table->n_philos && !is_simulation_finish(table))
        {
            // write(1, "Supervisor routine\n", 20);
           if(is_dead(&table->philos[i]) == true)
            {           
                // printf("Philosopher %d died\n", table->philos[i].id);
                set_bool(&table->control_mtx, &table->end_sim, true);
                print_action(DEAD, table, table->philos[i]);
                break;
            }
  //          break;
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
   while (i < table->n_philos || table->start_sim == true)
    {
        if(pthread_create(&table->philos[i].thread_id, NULL, philo_routine, \
                                                        &table->philos[i]))
            return(printf("%s"THREAD_ERROR"%s\n", RED, RES), 1);
        i++;
    }
    table->start_time = get_time(MILISECONDS);
    set_bool(&table->control_mtx, &table->start_sim, true);
    i = -1;
    while(++i < table->n_philos)
        pthread_join(table->philos[i].thread_id, NULL);
    set_bool(&table->control_mtx, &table->end_sim, true);
    // write(1, "Simulation ended\n", 18);
    pthread_join(table->supervisor, NULL);
    return(0);
}


        // printf("Valor retornado por pthread_join: %d\n", result);
        // printf("\n\ntable->philos[i].id = %d\n", philo->table->philos->id);
        // printf("table->philos[i].meal_counter = %ld\n", philo->table->philos->meal_counter);
        // printf("table->philos[i].last_meal_time = %ld\n", philo->table->philos->last_meal_time);
        // printf("table->philos[i].is_full = %d\n", philo->table->philos->is_full);
        // printf("end_sim = %d\n", philo->table->end_sim);
        // printf("all_philos_running = %d\n", philo->table->all_philos_running);
        // printf("n_philos_running = %ld\n\n", philo->table->n_philos_running);

        // printf("Valor retornado por pthread_join: %d\n", result);
        // printf("\n\ntable->philos[i].id = %d\n", table->philos->id);
        // printf("table->philos[i].meal_counter = %ld\n", table->philos->meal_counter);
        // printf("table->philos[i].last_meal_time = %ld\n", table->philos->last_meal_time);
        // printf("table->philos[i].is_full = %d\n", table->philos->is_full);
        // printf("end_sim = %d\n", table->end_sim);
        // printf("all_philos_running = %d\n", table->all_philos_running);
        // printf("n_philos_running = %ld\n\n", table->n_philos_running);


// void	*monitor_dinner(void *data)
// {
// 	int			i;
// 	t_table		*table;

// 	table = (t_table *)data;
// 	while (!all_threads_running(&table->table_mutex,
// 			&table->threads_running_nbr, table->philo_nbr))
// 		;
// 	while (!simulation_finished(table))
// 	{	
// 		i = -1;
// 		while (++i < table->philo_nbr && !simulation_finished(table))
// 		{
// 			if (philo_died(table->philos + i))
// 			{
// 				set_bool(&table->table_mutex, &table->end_simulation, true);
// 				write_status(DIED, table->philos + i, DEBUG_MODE);
// 			}
// 		}
// 	}
// 	return (NULL);
// }


        //busy wait for signal to start simulation
        //   while (!philo->table->start_sim);
        //loop executing whill all philos are alive
        //   while (philo->table->all_philos_running)
        //   {
        //    pthread_mutex_lock(&philo->write_mtx) ;
        //         write(1,"full\n", 5);
        //     pthread_mutex_unlock(&philo->write_mtx) ;
            //   }