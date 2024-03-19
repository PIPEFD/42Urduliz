/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbonilla <dbonilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 21:49:48 by codespace         #+#    #+#             */
/*   Updated: 2024/03/18 21:58:18 by dbonilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# define HEXX "0123456789abcdef"
# define HEX "0123456789ABCDEF"
# define MAX_INT 2147483647
# define MIN_INT -2147483648
# define RED "\033[0;31m"
# define GREEN "\033[0;92m"
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <sys/types.h>
# include <fcntl.h>

void	ft_putstr_fd(char *s, int fd);
int		ft_strncmp(char *s1, char *s2, size_t n);
double	atodbl(char *s);
#endif