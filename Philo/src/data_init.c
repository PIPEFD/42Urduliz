/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 13:43:22 by codespace         #+#    #+#             */
/*   Updated: 2024/04/08 11:18:33 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"
#include "../inc/errors.h"
#include "../inc/colors.h"


static int mem_alloc(t_table *table)
{
    table->end_sim = false;
    table->all_philos_running = false;
    table->n_philos_running = 0;
    table->start_sim = false;
    table->philos = malloc(table->n_philos * sizeof(t_philo));
    if (!table->philos) {
        return (1);
    }
    table->forks = malloc(table->n_philos * sizeof(t_fork));
    if (!table->forks) 
    {
        free(table->philos); 
        free(table->forks);
        return (1);
    }

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
        printf("table->forks[i].id = %d\n", table->forks[i].id);
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
        printf("Fork 1: %d\n", philo->first_fork->id);
        printf("philo_pos: %d\n", philo_pos);

        philo->second_fork = &(forks[philo_pos + 1 % philo->table->n_philos]);
        printf("philo_pos: %d\n", philo_pos);
        printf("Fork 2: %d\n", philo->first_fork->id);
    }
    else
    {
        philo->first_fork = &(forks[(philo_pos + 1 % philo->table->n_philos)]);
        philo->second_fork = &(forks[philo_pos]);    
    }
}

// static void assing_forks(int ss, t_fork *forks, unsigned int philo_pos)
// {
    
//     if (ss % 2 == 0)
//     {
//         philo.first_fork = &forks[philo_pos];
//         printf("Fork 1: %d\n", philo.first_fork->id);
//         printf("philo_pos: %d\n", philo_pos);
//         philo.second_fork = &forks[(philo_pos + 1) % ss];
//         printf("Fork 2: %d\n", philo.first_fork->id);
//         printf("philo_pos: %d\n", philo_pos);
//     }
//     else
//     {
//         philo.first_fork = &forks[(philo_pos) % ss];
//         printf("Fork 1: %d\n", philo.first_fork->id);
//         printf("philo_pos: %d\n", philo_pos);
//         philo.second_fork = &forks[philo_pos - 1];
//         printf("Fork 2: %d\n", philo.first_fork->id);
//         printf("philo_pos: %d\n", philo_pos);
//     }
// }


static int philos_init(t_table *table)
{
    int i;

    i = 0;
    while(i < table->n_philos)
    {
        table->philos[i].id = i + 1 ;
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
        printf("-> AQUI  DATA_INIT N_PHILOS: %ld\n", table->n_philos);
        printf("-> AQUI  DATA_INIT TIME_DIE: %ld\n", table->time_die);
        printf("-> AQUI  DATA_INIT TIME_EAT: %ld\n", table->time_eat);
        printf("-> AQUI  DATA_INIT TIME_SLEEP: %ld\n", table->time_sleep);
        printf("-> AQUI  DATA_INIT N_TIME_EAT: %ld\n", table->n_time_eat);
        i++;
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
    // printf("\n\ntable->philos[i].id = %d\n", table->philos->id);
    // printf("table->philos[i].meal_counter = %ld\n", table->philos->meal_counter);
    // printf("table->philos[i].last_meal_time = %ld\n", table->philos->last_meal_time);
    // printf("table->philos[i].is_full = %d\n", table->philos->is_full);
    // printf("end_sim = %d\n", table->end_sim);
    // printf("all_philos_running = %d\n", table->all_philos_running);
    // printf("n_philos_running = %ld\n\n", table->n_philos_running);
    write(1, "data_init\n", 10);
    return(0);
}
    // int i = 0;
    // while (i  < 4)
    // {    
    // i++;
    // }