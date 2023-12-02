/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 20:20:16 by codespace         #+#    #+#             */
/*   Updated: 2023/12/02 00:20:09 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
#define MINITALK_H


#include "/workspaces/42Urduliz/minitalk/libft/inc/libft.h"
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>


void    ft_send_singal(int pid, char s);
void    ft_rsingal(int signal);

#endif