/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ulstr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 14:11:55 by codespace         #+#    #+#             */
/*   Updated: 2023/07/12 14:58:59 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void ft_ulstr(char *string)
{
	int i;
	
	i = 0;
	while (string[i])
	{
		if (string[i] >= 'A' && 'Z' >= string[i])
			string[i] = string[i] + 32;
		else if (string[i] >= 'a' && 'z' >= string[i])
			string[i] = string[i] - 32;
		write (1, &string[i], 1);
		i++;
	}
}

int main (int argc, char **argv)
{
	if (argc == 2)
		ft_ulstr(argv[1]);
	write (1, "\n", 1);
	return (0);
}