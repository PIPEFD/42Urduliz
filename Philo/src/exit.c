/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbonilla <dbonilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 11:51:05 by dbonilla          #+#    #+#             */
/*   Updated: 2024/04/09 11:51:19 by dbonilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"
#include "../inc/errors.h"

void	safe_exit(t_table *table)
{
	unsigned int	i;

	pthread_mutex_destroy(&table->table_mtx);
	pthread_mutex_destroy(&table->write_mtx);
	pthread_mutex_destroy(&table->control_mtx);
	i = -1;
	while (++i < table->n_philos)
	{
		pthread_mutex_destroy(&table->forks[i].fork_mtx);
		pthread_mutex_destroy(&table->philos[i].philo_mtx);
	}
	free(table->philos);
	free(table->forks);
}