/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 23:23:14 by codespace         #+#    #+#             */
/*   Updated: 2023/07/12 23:25:35 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char *ft_strcpy(char *string1, char *string2)
{
	int i;

	i = 0;

	while (string2[i] != '\0')
	{
		string1[i] = string2[i];
		i++;
	}
	string1[i] = '\0';
	return (string1);
}