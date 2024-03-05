/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_safe_functions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:13:17 by codespace         #+#    #+#             */
/*   Updated: 2024/02/28 00:50:05 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

bool get_bool(t_mtx *mutex, bool *value)
{
    bool read_value;

    pthread_mutex_lock(mutex);
    read_value = *value;
    pthread_mutex_unlock(mutex);
    return(read_value);
}
long get_long(t_mtx *mutex, long *value)
{
    long read_value;
    
    pthread_mutex_lock(mutex);
    read_value = *value;
    pthread_mutex_unlock(mutex);
    return(read_value);
}

void    set_bool(t_mtx *mutex, bool *property, bool value)
{
    pthread_mutex_lock(mutex);
    *property = value;
    pthread_mutex_unlock(mutex);
}

void set_long(t_mtx *mutex, bool *property, long value)
{
    pthread_mutex_lock(mutex);
    *property = value;
    pthread_mutex_unlock(mutex);  
}

void increment_n_philos(_t_table *table)
{
    pthread_mutex_lix(&table->table_mtx);
    table->n_nphilos_running += 1
    if (table->n_philos_running == table->n_philos)
        seet_bool(&table->control_mtx &table->all_philos_running, true);
    pthread_mutex_unlock(&table->table_mtx);
}