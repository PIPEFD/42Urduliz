/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbonilla <dbonilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 20:20:04 by codespace         #+#    #+#             */
/*   Updated: 2023/12/06 16:52:41 by dbonilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

static	void	sig_handler(int sig)
{
	static int	r = 0;

	if (sig == SIGUSR1)
		++r;
	else
	{
		exit(0);
	}
}

void	ft_send_singal(int pid, char *s)
{
	int				i;
	unsigned char	c;

	while (*s)
	{
		i = 8;
		c = *s++;
		while (i--)
		{
			if (c >> i & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			usleep(200);
		}
	}
	i = 8;
	while (i--)
	{
		kill(pid, SIGUSR1);
		usleep(200);
	}
}

int	main(int argc, char **argv)
{
	if (argc != 3)
	{
		ft_putstr_fd("Error Arguments\n", STDERR_FILENO);
		return (1);
	}
	signal (SIGUSR1, sig_handler);
	signal (SIGUSR2, sig_handler);
	ft_send_singal(ft_atoi(argv[1]), argv[2]);
	while (1)
		pause();
	return (0);
}
