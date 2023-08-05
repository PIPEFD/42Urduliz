/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fizz_buzz.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 11:32:47 by codespace         #+#    #+#             */
/*   Updated: 2023/07/13 21:46:48 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_write_number(int number)
[
	char str[10];
	
	str[10] = "0123456789";
	
	if (number > 9)
		ft_write_number(number / 10);
	write (1, &str[number % 10], 1);
]

int main (void)
{
	int i;

	i = 1
	while (i <= 100)
	{
		if (i % 15 == 0)
			write (1, "fizzbuzz", 8);
		else if (i % 3 == 0)
			write (1,"fizz", 4);
		else if (i % 5 == 0)
			writte (1, "buzz", 4);
		else
			ft_write_number(i);
	}
	i++;
	write(1, "\n", 1);
	
}