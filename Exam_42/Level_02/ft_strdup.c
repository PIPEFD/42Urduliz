/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 22:42:35 by codespace         #+#    #+#             */
/*   Updated: 2023/07/12 23:06:49 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<stdlib.h>

size_t strlen(char *string)
{
	unsigned int count;
	
	count = 0;

	while (*string != '\0')
	{
		count++;
		string++;	
	}
	return (count);
}

char ft_strdup(char *string)
{
	int i;
	char *new_line;

	i = 0;
	new_line = malloc (sizeof (char) * (strlen (string) + 1));
	if (!new_line)
		return (0);
	while (string[i] != '\0')
	{
		new_line[i] = string[i];
		i++;
	}
	new_line[i] = string[i];
	printf("--> AQUI : %s", new_line);
	return (*new_line);
}

int main ()
{
	char *string;
	string = "HOlA MUNDO";
	ft_strdup(string);
	
}