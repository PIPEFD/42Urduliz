/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbonilla <dbonilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 11:01:59 by codespace         #+#    #+#             */
/*   Updated: 2024/04/09 20:14:26 by dbonilla         ###   ########.fr       */
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
long	get_time(t_time_format time_format)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
    if (MILISECONDS == time_format)
		return (time.tv_sec * 1e3 + time.tv_usec / 1e3);
	else if (MICROSECONDS == time_format)
		return (time.tv_sec * 1e6 + time.tv_usec);
	return (42);
}
bool  is_dead(t_philo *philo)
{
    long elapsed_time;
    long t_to_die;
    if(get_bool(&philo->philo_mtx, &philo->is_full) == true)
        return (false); 
    elapsed_time =  get_time(MILISECONDS) - get_long(&philo->philo_mtx, &philo->last_meal_time);
    // printf("last_meal %li\n", last_meal);
    //printf("elapsed_time %li\n", elapsed_time);
    //printf("time_die %li\n", philo->table->time_die);
    t_to_die = philo->table->time_die;
    //printf("t_to_die %li\n", t_to_die);
    //printf("philo id: %i\n", philo->id);
    if (elapsed_time > t_to_die)
        return (true);
    return (false);
}


void usleep_mod(long wait_time, t_table *table)
{
    long    t_start;
    long    t_curr;
    long    t_remaining;

    t_start = get_time(MICROSECONDS);
    while(get_time(MICROSECONDS) - t_start < wait_time)
    {
        if (is_simulation_finish(table))
            break;
        t_curr = get_time(MICROSECONDS) - t_start;
        t_remaining = wait_time - t_curr;
        if (t_remaining > 1e4)
            usleep(t_remaining / 2);
        else
        {
            while(get_time(MICROSECONDS) - t_start < wait_time)
                    ;
        }
    }
}