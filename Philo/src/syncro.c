/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syncro.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 10:07:05 by codespace         #+#    #+#             */
/*   Updated: 2024/04/08 23:23:56 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"


void	wait_all_threads(t_table *table)
{
    // write(1, "Waiting all threads\n", 20);
	while (get_bool(&table->table_mtx, &table->all_philos_running) == false)
		;
}


bool all_philos_running(t_mtx *mutex, t_table *table)
{
    // printf("get_bool %i\n", get_bool(mutex, &table->all_philos_running));
    return (get_bool(mutex, &table->all_philos_running));
}

bool is_simulation_finish(t_table *table)
{
    return (get_bool(&table->control_mtx, &table->end_sim));
}

void    simulation_fair(t_philo *philo)
{
    if (philo->table->n_philos % 2 == 0)
    {
        if (philo->id % 2 == 0)
            usleep_mod(1e3, philo->table);
    }
    else
    {
        if (philo->id % 2 == 1)
            thinking(philo);        
    }
}
