/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 11:57:47 by codespace         #+#    #+#             */
/*   Updated: 2023/07/10 12:10:18 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdio.h>

size_t ft_strlen(char *string)
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

int	main()
{
	char *string;
	
	
	string = "HOlA MUNDO!";
	
	printf ("CONTADOR -->> %ld", ft_strlen(string));
	printf ("\n");
	return (0);
}