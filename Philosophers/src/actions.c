/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 15:15:41 by codespace         #+#    #+#             */
/*   Updated: 2024/02/26 15:48:06 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void eating(t_philo *philo)
{
    pthread_mutex_lock(&philo->first_fork->fork_mtx);
    print_action(TAKING_A_FORK, philo->table, *philo);
    pthread_mutex_lock(&philo->second_fork->fork_mtx);
    print_action(TAKING_A_FORK, philo->table, *philo);
    print_action(EATING, philo->table, *philo);
    set_long(&philo->philo_mtx, &philo->last_meal_time, get_time(MILISECONDS));
    philo->meal_counter++;
    if(philo->meal_counter == philo->table->n_times_eat)
        philo->is_ful = true;
    usleep_mod(philo->table->time_eat * 1000, philo->table);
    pthread_mutex_unlock(&philo->first_fork->fork_mtx);
    pthread_mutex_unlock(&philo->second_fork->fork_mtx);    
}

void thinking(t_philo *philo)
{
    long    t_think;
    
    if (philo->table->n_philos % 2 == 0)
        return ;
    t_think = (philo->table->time_eat * 2 - philo->table->time_sleep) * 1e3;
    if (t_think < 0)
        t_think = 0;
    usleep_mod(t_think * 0.5, philo->table);
}