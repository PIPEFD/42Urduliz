/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbonilla <dbonilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 18:42:38 by codespace         #+#    #+#             */
/*   Updated: 2023/11/20 21:52:00 by dbonilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

static void	init_params(unsigned int *n, int *sign, unsigned int *digits)
{
	*n = 0;
	*sign = 1;
	*digits = 0;
}

static int	ft_intmax(unsigned int n, int sign, char *string)
{
	return (n == 2147483647
		&& (*string == '9' || (*string == '8' && sign == 1)));
}

int	ft_int(char *string)
{
	unsigned int	n;
	int				sign;
	unsigned int	digits;

	init_params(&n, &sign, &digits);
	if (*string == '+' || *string == '-')
		if (*string++ == '-')
			sign = -1;
	while (*string)
	{
		if (!(ft_digit(*string) && digits < 11 && n <= 2147483647))
			return (0);
		if (ft_intmax(n, sign, string))
			return (0);
		n = n * 10 +(*string++ - '0');
		digits++;
	}
	if (digits == 0)
		return (0);
	return (1);
}
