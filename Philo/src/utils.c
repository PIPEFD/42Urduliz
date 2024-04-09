/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 11:01:59 by codespace         #+#    #+#             */
/*   Updated: 2024/04/08 23:27:19 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

bool is_space(char c)
{
    return ((c == ' ') || (c >= 9 && c <= 13));
}

bool is_sign(char c)
{
    return ((c == '-') || (c == '+'));
}
long get_time(t_time_format time_format)
{
    struct timeval  time;
    
    gettimeofday(&time, NULL);
    if(time_format == MILISECONDS)
        return ((time.tv_sec * 1e3) + (time.tv_usec / 1e3));
    else if (time_format == MICROSECONDS)
        return ((time.tv_sec * 1e3) + time.tv_usec );
    return (42);

}
bool  is_dead(t_philo *philo)
{
    long dif;
    long last_meal;
    last_meal = get_long(&philo->philo_mtx, &philo->last_meal_time);
    // printf("last_meal %li\n", last_meal);
    dif = get_time(MILISECONDS) - last_meal;
    return (dif > philo->table->time_die);
}


void usleep_mod(long wait_time, t_table *table)
{
    long    t_start;
    long    t_curr;
    long    t_remaining;

    t_start = get_time(MICROSECONDS);
    while((get_time(MICROSECONDS) - t_start) < wait_time)
    {
        if (is_simulation_finish(table) == true)
            return;
        t_curr = get_time(MICROSECONDS) - t_start;
        t_remaining = wait_time - t_curr;
        if (t_remaining > 1000)
            usleep(t_remaining / 2);
        else
        {
            while((get_time(MICROSECONDS) - t_start) < wait_time);
        }
    }
}