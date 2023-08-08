/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 22:01:19 by codespace         #+#    #+#             */
/*   Updated: 2023/08/05 22:14:28 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void rev_print(char *string)
{
	int i;
	i = 0;

	while (string[i])	
		i++;
	while (i)
		write(1, &string[--i], 1);
}

int main (int argc,  char **argv)
{
	if(argc == 2)
		rev_print(argv[1]);
	write(1, "\n", 1);
	return(0);
}