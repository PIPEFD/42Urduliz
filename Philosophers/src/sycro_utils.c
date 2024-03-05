/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sycro_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 15:06:38 by codespace         #+#    #+#             */
/*   Updated: 2024/02/26 15:13:26 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"



void wait_all_threads(t_table *table)
{
    return (get_bool(mutex, &table->all_philos_running));
}

bool all_philos_running(t_mtx *mutex, t_table *table)
{
    return (get_bool(mutex, &table->all_philos_running));
}


bool is_simulation_finish(t_table *table)
{
    return (get_bool(&table->control_mtx, &table->end_sim))
}


void    make_simulation_fair(t_philo *philo)
{
    if (philo->table->n_philos % 2 == 0)
    {
        if (philo->id % 2 == 0)
            useep_mod(1e3, philo->table);
    }
    else
    {
        if (philo->id % 2 == 1)
            thinking(philo);        
    }
}