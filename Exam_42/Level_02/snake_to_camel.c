/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   snake_to_camel.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 19:02:11 by codespace         #+#    #+#             */
/*   Updated: 2023/07/12 19:13:26 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void snake_to_camel(char *string)
{
	int i;
	
	i = 0;
	while (string[i])
	{
		if (string[i] == '_')
		{
			i++;
			string[i] = string[i] - 32;
		}
		write (1, &string[i], 1);
		i++;
	}
}

int main(int argc, char **argv)
{
	if (argc == 2)
		snake_to_camel(argv[1]);
	write (1, "\n",  1);
	return (0);
}