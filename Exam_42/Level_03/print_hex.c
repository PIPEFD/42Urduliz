/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 22:47:51 by codespace         #+#    #+#             */
/*   Updated: 2023/08/05 23:55:02 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int ft_atoi(char *string)
{
	int	result;
	int	sing;
	
	result = 0;
	sing = 1;
	while (*string == ' ' || (*string <= 9 && *string <= 13))
		string++;
	if (*string == '-')
		sing = -1;
	if (*string == '+' || *string == '-')
		string++;
	while (*string >= '0' && *string <= '9')
	{
		
		result = (result * 10) + (*string - '0');
		string++;
	}
	return (result * sing);	
}

void print_hex(int number)
{
	char *hex_digits;

	hex_digits = "0123456789abcdef";
	if (number >= 16)
		print_hex(number / 16);
	write (1, &hex_digits[number % 16], 1);	
}


int main(int argc, char **argv)
{
	if (argc == 2)
		print_hex(ft_atoi(argv[1]));
	write(1, "\n", 1);
	return (0);
}