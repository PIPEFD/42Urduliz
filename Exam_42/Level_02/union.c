/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 12:23:25 by codespace         #+#    #+#             */
/*   Updated: 2023/07/15 13:16:58 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void print_union (char *string1, char *string2)
{
	int string[128] = {0};
	int temp;
	
	while(*string1 != '\0')
	{
		temp = *string1;
		if (string[temp] == 0)
		{
			write(1, string1 , 1);
			string[temp] = 1;
		}
		string1++;
	}
	while (*string2 != '\0')
	{
		temp = *string2;
		if(string[temp] == 0)
		{
			write(1, string2, 1);
			string[temp]= 1;
		}
		string2++;
	}
	
}

int main (void)
{
	// if (argc == 3)
		print_union("Hola","mundo");
	write (1, "\n", 1);
	return (0);
}