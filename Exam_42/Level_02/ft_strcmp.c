/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 22:17:18 by codespace         #+#    #+#             */
/*   Updated: 2023/08/05 22:36:57 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
// #include <string.h>

int main (int argc, char **argv)
{
	if (argc == 3)
		printf("%d\n", ft_strcmp(argv[1], argv[2]));
		// printf("%d\n", strcmp(argv[1], argv[2]));
	return (0);
}

int ft_strcmp(char *string_1, char *string_2)
{
	int i;

	i = 0;
	while (string_1[i] != '\0' && string_2[i] != '\0' && string_1[i] == string_2[i])
	{
		i++;
	}
	return(string_1[i] - string_2[i]);		
}