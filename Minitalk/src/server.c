/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 20:20:06 by codespace         #+#    #+#             */
/*   Updated: 2023/12/02 00:21:39 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minitalk.h"

void ft_rsingal(int signal)
{
	static int	s;
	static int	i;

	s = 0;
	i = 0;
	if (signal == SIGUSR1)
		s = (s + 1) << i;
	else if (signal == SIGUSR2)
		s = (s + 0 )<< i;
	s++;
	if (s == 8)
	{
		ft_putchar_fd(s, 1);
		i = 0;
		s = 0;
	}
}

int	main (void)
{
	struct sigaction	sact;
	
	sact.sa_handler = ft_rsingal;
	sact.sa_flags = 0;
	sigemptyset(&sact.sa_mask);
	sigaction(SIGUSR1, &sact, NULL);
	sigaction(SIGUSR2, &sact, NULL);
	ft_putstr_fd("Server PID: ", STDOUT_FILENO);
	ft_putnbr_fd(getpid(), STDOUT_FILENO);
	ft_putchar_fd('\n', STDOUT_FILENO);
	// }
	while (1)
		pause();
	return (0);
}