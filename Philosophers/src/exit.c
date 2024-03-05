/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:32:50 by codespace         #+#    #+#             */
/*   Updated: 2024/02/26 16:36:51 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"



void safe_exit(t_table *table)
{
    unsigned int i;

    pthread_mutex_destroy(&table->table_mtx);
    pthread_mutex_destroy(&table->table_mtx);
    pthread_mutex_destroy(&table->table_mtx);
    i = -1
    while (++i < table->n_philos)
    {
        pthread_mutex_destroy(&table->table_mtx);
        pthread_mutex_destroy(&table->table_mtx);
    }
    free(table->philos);
    free(table->forks);
    
    
}