/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 00:04:28 by codespace         #+#    #+#             */
/*   Updated: 2024/02/25 15:52:16 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"
#include "../inc/error.h"
#include "../inc/colors.h"

static int memory_allocation(t_table *table)
{
    table->forks = malloc(table->n_philos * sizeof(t_fork));
    if (!table->forks)
        return(1);
    table->philos = malloc(table->n_philos * sizeof(t_philo));
    if (!table->philos)
    {
        free(table->forks);
        return (1);
    }
    return(0);
}

static int init_mutexes(t_table *table)
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


static int init_philos(t_table *table)
{
    int i;

    i = 0;
    while (i < table->n_philos)
    {
        table->philos[i].id = i + 1;
        table->philos[i].meal_counter = 0;
        table->philos[i].last_meal_time = 0;
        table->philos[i].is_full = 0;
        table->philos[i].table = 0;
        if(pthread_mutex_init(&table->philos[i].philo_mtx,NULL))
        {
            while (--i >= 0)
                pthread_mutex_destroy(&table->philos[i].philo_mtx);
            return(1);
        }
        assing_forks(&table->philos[i],table->forks, i);
        i++;
    }
    return(0);    
}

int init_data(t_table *table)
{
    if (memory_allocation(table))
        return(printf("%s"MALLOC_ERROR"%s\n",RED, RES), 1);
    if (init_mutexes(table)|| init_philos(table))
    {
        free(table->forks);
        free(table->philos);
        return(printf("%s"MUTEX_ERROR"%s\n", RED, RES), 1);
    }
    return (0);
}