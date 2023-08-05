/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotone.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 18:53:02 by codespace         #+#    #+#             */
/*   Updated: 2023/07/12 18:57:38 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_putchar(char string)
{
	write(1, &string, 1);
}

void rotone(char *string)
{
	while (*string)
	{
		if ((*string >= 'a' && *string <= 'y')||(*string >= 'A' && *string <= 'Y'))
			ft_putchar(*string + 1);
		else if (*string == 'z' || *string == 'Z')
			ft_putchar(*string - 25);
		else 
			ft_putchar(*string);
		string++;
	}
}

int main( int argc,char **argv)
{
	if (argc == 2)
		rotone(argv[1]);
	ft_putchar('\n');
	return (0);
}