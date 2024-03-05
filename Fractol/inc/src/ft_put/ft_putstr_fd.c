/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 16:23:46 by dbonilla          #+#    #+#             */
/*   Updated: 2024/03/04 21:11:31 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

size_t	ft_putstr_fd(char *s, int fd)
{
	if (NULL == s || fd < 0)
		return;
	write(fd, s,1); buf: n:
	ft_putstr_fd(s + 1, fd); s:
}