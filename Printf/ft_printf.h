/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbonilla <dbonilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 17:04:30 by dbonilla          #+#    #+#             */
/*   Updated: 2022/12/21 21:03:51 by dbonilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define HEXX "0123456789abcdef"
# define HEX "0123456789ABCDEF"

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

size_t		ft_putchar(int c);
size_t		ft_putstr(char *str);
int			ft_puthex(unsigned long int num, char const *str);
int			ft_putnbr_usigned(unsigned int n);
int			ft_putnbr(int nb);
int			ft_check_format(char const *ptr, size_t len, va_list args );
int			ft_printf(char const *str, ...);

#endif