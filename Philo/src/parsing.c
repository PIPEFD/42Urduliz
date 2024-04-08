/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 10:55:16 by codespace         #+#    #+#             */
/*   Updated: 2024/04/06 01:54:34 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"
#include "../inc/errors.h"


static long  ft_atol(long *nbr, char *str, long i)
{
    long    j;
    
    j = 0;
    while (is_space(str[j]) == true)
        j++;
    if (is_sign(str[j])== true)
    {
        if(str[j] == '-')
        {
            *nbr = 1;
            return (0);
        }
        j++;
    }
    while (str[j] >= '0' && str[j] <= '9')
    {
        *nbr = *nbr * 10 + (str[j] - '0');
        j++;
    }
    if (str[j] || ((*nbr == 0) && (i == 1 || i == 5)) || *nbr > INT_MAX)
        return(0);
    return(1);
}

static void fill_data(t_table *table, long nbr, long i)
{
    if (i == 1)
        table->n_philos     =	nbr; 
                     
    if (i == 2)
        table->time_die     =   nbr;
    if (i == 3)
        table->time_eat		=	nbr;
    if (i == 4)
        table->time_sleep   =   nbr;
    if (i == 5)
        table->n_time_eat	=	nbr;   


}
int args_parsing(t_table *table, char **argv)
{
    long    i;
    long    nbr;
    memset(table, 0, sizeof(t_table));
    i = 0;
    nbr = 0;
    while (argv[++i] )
    {
        if (ft_atol(&nbr, argv[i], i) == 0)
        {
            if(i == 1 && nbr == 0)
                return (help(PHILOS_ZERO_ERROR), 1);
            else if (i == 4 && nbr == 0)
                return (help(N_EAT_ZERO_ERROR), 1);
            else if (nbr > INT_MAX)
                return (help(INT_MAX_ERROR), 1);
            else   
                return (help(NUMBER_ERROR), 1);     
        }
        else
            fill_data(table, nbr, i);
        write(1, "args_parsing\n", 13);
        nbr = 0;
    }
    return (0);
    
}
// printf("-> I %ld\n", i);
// printf("-> AQUI TABLE N_PHILOS: %ld\n", table->n_philos);
// printf("-> AQUI TABLE TIME_DIE: %ld\n", table->time_die);
// printf("-> AQUI TABLE TIME_EAT: %ld\n", table->time_eat);
// printf("-> AQUI TABLE TIME_SLEEP: %ld\n", table->time_sleep);