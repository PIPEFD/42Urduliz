/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbonilla <dbonilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 13:43:22 by codespace         #+#    #+#             */
/*   Updated: 2024/04/09 19:27:44 by dbonilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"
#include "../inc/errors.h"
#include "../inc/colors.h"


static int mem_alloc(t_table *table)
{
    table->start_sim = false;
    table->end_sim = false;
    table->all_philos_running = false;
    table->n_philos_running = 0;
    table->start_time = 0;
    table->full_philos = 0;
    table->philos = malloc(table->n_philos * sizeof(t_philo));
    if (!table->philos) 
    {
        free(table->forks); 
        return (1);
    }
    table->forks = malloc(table->n_philos * sizeof(t_fork));
    if (!table->forks) 
        return (1);
    return 0;
}
static int mutex_init(t_table *table)
{
    int i;
    if(pthread_mutex_init(&table->table_mtx, NULL))
        return (1);
    if(pthread_mutex_init(&table->control_mtx, NULL))
        return (1);
    if(pthread_mutex_init(&table->write_mtx, NULL))
        return (1);
    i = 0;
    
    while (i < table->n_philos)
    {

        table->forks[i].id = i;
        if(pthread_mutex_init(&table->forks[i].fork_mtx, NULL))
        {
            while (--i >= 0)
                pthread_mutex_destroy(&table->forks[i].fork_mtx);
            return(1);
        }
        i++;
    }
    return(0);
}

static void assing_forks(t_philo *philo, t_fork *forks, unsigned int philo_pos)
{
    if (philo->id % 2 == 0)
    {
        philo->first_fork = &(forks[philo_pos]);
        philo->second_fork = &(forks[philo_pos + 1 % philo->table->n_philos]);
    }
    else
    {
        philo->first_fork = &(forks[(philo_pos + 1 % philo->table->n_philos)]);
        philo->second_fork = &(forks[philo_pos]);    
    }
}

static int philos_init(t_table *table)
{
    int i;

    i = -1;
    while(++i < table->n_philos)
    {
        table->philos[i].id = i + 1;
        table->philos[i].meal_counter = 0;
        table->philos[i].last_meal_time = 0;
        table->philos[i].is_full = false;
        table->philos[i].table = table;
        if(pthread_mutex_init(&table->philos[i].philo_mtx, NULL))
        {
            while (--i > 0)
                pthread_mutex_destroy(&table->philos[i].philo_mtx);
            return(1);
        }
        assing_forks(&table->philos[i], table->forks, i);
    }
    return(0);
}

int data_init(t_table *table)
{

    if(mem_alloc(table))
        return(printf("%s"MALLOC_ERROR"%s\n", RED, RES), 1);
    if (mutex_init(table)|| philos_init(table))
    {
        free(table->forks);
        free(table->philos);
        return(printf("%s"MUTEX_ERROR"%s\n", RED, RES), 1);
    }
    write(1, "data_init\n", 10);
    return(0);
}