/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 16:31:48 by codespace         #+#    #+#             */
/*   Updated: 2023/08/05 16:38:42 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>


void first_word(char *string)
{
	int i;
	
	i = 0;

	while (string[i] == 32 || string[i] == 9)
	i++;
	while ((string[i] != 9 && string[i] != 32) && string[i])
	{
		write (1, &string[i], 1);
		i++;
	}
	
}

int main(int argc, char **argv)
{
	if(argc == 2)
		first_word(argv[1]);
	write(1, "\n", 1);
	return (0);
} 