/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ulstr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 12:15:22 by codespace         #+#    #+#             */
/*   Updated: 2023/07/10 13:00:34 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void ulstr(char *string)
{
	int	i;
	char	letter;

	i = 0;
	while (string[i])
	{
		letter = string[i];
		if(string[i] >= 'A' && 'Z' >= string[i] )
			letter += 32;
		if (string[i] >= 'a' && 'z' >= string[i])
			letter -= 32;
		write (1, &letter, 1);
		i++;
	}
    
}

int main (int argc, char **argv)
{
    if (argc == 2)
		ulstr(argv[1]);
	write (1, "\n", 1);
    return(0);

}


