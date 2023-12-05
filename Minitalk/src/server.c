/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 20:20:06 by codespace         #+#    #+#             */
/*   Updated: 2023/12/05 17:56:23 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

#include "stdio.h"
void ft_rsignal(int sig, siginfo_t *info, void *context)
{
    static int		i = 0;		
	static unsigned char	c = 0;
	static pid_t pd = 0;
	
	// printf("entramos con señal %i\n", sig);

	(void)context;
	if (!pd)
		pd = info->si_pid;
	c |= (sig == SIGUSR2);
	if (++i == 8)
	{
		i = 0;
		if (!c) 
		{
			kill(pd, SIGUSR2);
			pd = 0;
			return ;
		}
		ft_putchar_fd(c, 1);
		c = 0;
		kill(pd,SIGUSR1);
	}
	else 
		c <<= 1;
}

int	main (void)
{
	struct sigaction	act;
	
    ft_putstr_fd("Server PID: ", STDOUT_FILENO);
    ft_putnbr_fd(getpid(), STDOUT_FILENO);
    ft_putchar_fd('\n', STDOUT_FILENO);
	act.sa_sigaction  = ft_rsignal;
	act.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &act, 0);
	sigaction(SIGUSR2, &act, 0);
	while (1)
			pause();
	return (0);
}