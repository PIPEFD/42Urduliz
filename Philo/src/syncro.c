/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syncro.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbonilla <dbonilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 10:07:05 by codespace         #+#    #+#             */
/*   Updated: 2024/04/09 20:06:12 by dbonilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"


void	wait_all_threads(t_table *table)
{
    write(1, "Waiting all threads\n", 20);
	while (get_bool(&table->table_mtx, &table->all_philos_running))
		;
}
bool	all_philos_running(t_mtx *mutex, long *threads,
		long philo_nbr)
{
	bool	ret;

	ret = false;
	pthread_mutex_lock(mutex);
	if (*threads == philo_nbr)
		ret = true;
	pthread_mutex_unlock(mutex);
	return (ret);
}



bool is_simulation_finish(t_table *table)
{
    // printf("get_bool %i\n", get_bool(&table->control_mtx, &table->end_sim));
    return (get_bool(&table->table_mtx, &table->end_sim));
}

void    simulation_fair(t_philo *philo)
{
    if (philo->table->n_philos % 2 == 0)
    {
        printf("philo %i\n", philo->id);
        if (philo->id % 2 == 0)
            usleep_mod(1e6, philo->table);
    }
    else
    {
        write(1, "Simulation fair\n", 17);
        if (philo->id % 2 == 1)
            thinking(philo);        
    }
}
