/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 20:20:04 by codespace         #+#    #+#             */
/*   Updated: 2023/12/02 00:15:44 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "/workspaces/42Urduliz/minitalk/inc/minitalk.h"

void ft_send_singal(int pid, char s)
{
    int i;

    while (s)
    {
        i = 0;
        while (i < 8)
        {
            if ((s >> i) & i)
                kill(pid, SIGUSR1);
            else
                kill(pid, SIGUSR2);
            usleep(100);
            usleep(100);
            i++;
        }
    }
}


int main (int argc, char **argv)
{
    int i;
    while (argc)
    {
        if (argc != 3)
        {
            ft_putstr_fd("Error Arguments\n",STDERR_FILENO);
            return (1);
        }  
        while (argv[2][i])
        {
            ft_send_singal(ft_atoi(argv[1]), argv[2][i]);
            i++;
        }
    }
    ft_send_singal(ft_atoi(argv[1]), '\n');
    return (0);
}