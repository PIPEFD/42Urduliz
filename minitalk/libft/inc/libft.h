/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbonilla <dbonilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 20:20:11 by codespace         #+#    #+#             */
/*   Updated: 2023/12/06 16:50:05 by dbonilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <signal.h>

int				ft_atoi(const char *str);

size_t			ft_putchar_fd(char c, int fd);

size_t			ft_putnbr_fd(int nb, int fd);

size_t			ft_putchar_fd(char c, int fd);

size_t			ft_putstr_fd(char *s, int fd);

#endif