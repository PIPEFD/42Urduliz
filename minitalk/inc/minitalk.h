/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbonilla <dbonilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 20:20:16 by codespace         #+#    #+#             */
/*   Updated: 2023/12/06 16:38:12 by dbonilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include "../libft/inc/libft.h"
# define TRUE SIGUSR1 
# define FALSE SIGUSR2 

void	ft_send_singal(int pid, char *s);

void	ft_rsignal(int sig, siginfo_t *info, void *ucontent);

#endif