/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 17:15:30 by codespace         #+#    #+#             */
/*   Updated: 2023/08/05 17:33:33 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
int ft_atoi(const char *string)
{
	int result;
	int sign;
	
	result = 0;
	sign = 1;
	
	while (*string == ' ' ||(*string >= 9 && *string <= 13))
		string++;
	if (*string == '-')
		sign = -1;
	if (*string == '+' || *string == '-')
		string++;
	while (*string >= '0' && *string <= '9')
	{
		result = (result * 10) + (*string - '0');
		string++;
	}
	return (sign * result);
}

int main (void)
{
	char *number;

	number = "12345678";
	printf("%d\n", ft_atoi(number));
	printf("%d\n", atoi(number));
	return (0);
}