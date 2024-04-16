/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 11:01:59 by codespace         #+#    #+#             */
/*   Updated: 2024/04/09 21:17:20 by codespace        ###   ########.fr       */
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
void	get_time()
{
	struct timeval	time;

	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}
bool  is_dead(t_philo *philo)
{
    long elapsed_time;
    long t_to_die;
    if(get_bool(&philo->philo_mtx, &philo->is_full) == true)
        return (false); 
    elapsed_time =  get_time(MILISECONDS) - get_long(&philo->philo_mtx, &philo->last_meal_time);
    // printf("last_meal %li\n", last_meal);
    t_to_die = philo->table->time_die / 1e3;Œ
    if (elapsed_time > t_to_die)
        return (true);
    return (false);
}


// void usleep_mod(long wait_time, t_table *table)
// {
int ft_usleep(size_t milliseconds)
{
	size_t	start;

	start = get_time();
	while ((get_time() - start) < milliseconds)
		usleep(500);
	return (0);
}

// }
