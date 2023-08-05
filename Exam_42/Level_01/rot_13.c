/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_13.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 21:26:25 by codespace         #+#    #+#             */
/*   Updated: 2023/07/12 21:46:40 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void rot_13(char *string)
{
	int i;
	
	i = 0;
	while(string[i])
	{
		if (string[i] >= 'a' && string[i] <= 'z')
			string[i] = (string[i] - 'a' + 13) % 26 + 'a';
		else if (string[i] >= 'A' && string[i] <= 'Z')
				string[i] = (string[i] - 'A' + 13) % 26 + 'A';
		write(1, &string[i], 1);
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		rot_13(argv[1]);
	write(1, "\n", 1);
	return (0);
}

