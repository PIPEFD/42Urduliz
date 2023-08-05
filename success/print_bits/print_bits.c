/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 09:14:28 by codespace         #+#    #+#             */
/*   Updated: 2023/07/12 09:22:51 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void print_bits (unsigned char octet)
{
	int i;
	unsigned int bit;
	
	i = 8;
	while (i--)
	{
		bit = (octet >> i & 1) + '0';
		write (1, &bit, 1);
	}
}
