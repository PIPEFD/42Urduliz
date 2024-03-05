/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 14:51:32 by codespace         #+#    #+#             */
/*   Updated: 2024/02/26 15:06:13 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"


long    get_time(t_time_format time_format)
{
    struct timeval time;
    
    gettimeofday(&time, NULL);
    if(time_format == MILISECONDS)
        return((time.tv_usec * 1e3) + (time.tv_usec / 1e3));
    else if (time_format == MICROSECONDS)
        return((time.tv_usec * 1e3) + (time.tv_usec / 1e3));
    return (42);
}

bool is_dead(t_philo *philo)
{
    long dif;
    long last_meal;
    
    last_meal = get_long(&philo->philo_mtx, &philo->last_meal_time);
    dif = get_time(MILISECONDS) -last_meal;
    return (dif > philo->table->time_die)

}

void usleep_mod(long wait_time, t_table *table)
{
    long    t_start;
    long    t_curr;
    long    t_reamaining;

    t_start = get_time(MICROSECONDS);
    while ((get_time(MICROSECONDS) - t_start) < wait_time)
    {
        if (is_simulation_finish(table) == true)
            return;
        t_curr = get_time(MICROSECONDS) - t_start;
        t_reamaining =wait_time -t_curr;
        if (t_reamaining > 1000)
            usleep(t_reamaining / 2);
        else
        {
            while((get_time(MICROSECONDS) - t_start) < wait_time)
                ;
        }
    }
    
    
}