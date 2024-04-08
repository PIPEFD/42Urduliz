/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_safe.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbonilla <dbonilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 09:37:39 by codespace         #+#    #+#             */
/*   Updated: 2024/04/08 17:15:06 by dbonilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"


bool get_bool(t_mtx *mtx, bool *value)
{
    bool ret;
    ret = false;

    pthread_mutex_lock(mtx);
    if (value != NULL) {
        ret = *value;
    }
    pthread_mutex_unlock(mtx);
    return ret;    
}

long get_long(t_mtx *mtx, long *value)
{
    long ret; 
    ret = 0;
    pthread_mutex_lock(mtx);
    if (value != NULL){
        ret = *value;
    }
    pthread_mutex_unlock(mtx);
    return ret;    
}

void set_bool(t_mtx *mtx, bool *var, bool value)
{
    pthread_mutex_lock(mtx);
    *var = value;
    pthread_mutex_unlock(mtx);
}

void set_long(t_mtx *mtx, long *var, long value)
{
    pthread_mutex_lock(mtx);
    *var = value;
    pthread_mutex_unlock(mtx);
}
void increment_n_philos(t_table *table)
{
    pthread_mutex_lock(&table->table_mtx);
    table->n_philos_running += 1;
    if (table->n_philos_running == table->n_philos)
        set_bool(&table->control_mtx, &table->all_philos_running, true);
    pthread_mutex_unlock(&table->table_mtx);
}
