/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 20:04:38 by codespace         #+#    #+#             */
/*   Updated: 2023/07/12 21:18:02 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

	
void repeat_alpha(char *string)
{
	int	i;
	int	repeat;
	
	i = 0;
	while (string[i])
	{
		repeat = 1;
		if (string[i] >= 'a' && string[i] <= 'z')
			repeat += string[i] - 'a';
		else if (string[i] >= 'A' && string[i] <= 'Z')
			repeat += string[i] - 'A';
		while (repeat)
		{
			write(1, &string[i], 1);
			repeat--;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		repeat_alpha("abc");	
	write(1, "\n", 1);
	return (0);
}

	
	
	
	
	
	
	