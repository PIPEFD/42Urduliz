/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 08:58:05 by codespace         #+#    #+#             */
/*   Updated: 2023/07/12 09:05:04 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_strlen(char *string)
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