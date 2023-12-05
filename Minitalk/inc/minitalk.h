/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 20:20:16 by codespace         #+#    #+#             */
/*   Updated: 2023/12/05 17:17:28 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
#define MINITALK_H


#include "../libft/inc/libft.h"



#define TRUE SIGUSR1 
#define FALSE SIGUSR2 

void    ft_send_singal(int pid, char *s);

void    ft_rsignal(int sig, siginfo_t *info, void *ucontent);

#endif