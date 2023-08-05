/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 17:13:43 by codespace         #+#    #+#             */
/*   Updated: 2023/08/05 17:54:21 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	if (*string == '-' || *string == '+')
		string++;
	while (*string >= '0' && *string <= '9')
	{
		result = (result * 10) + (*string - '0');
		string++;
	}
	return (result * sign);
}
