/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbonilla <dbonilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 03:28:46 by dbonilla          #+#    #+#             */
/*   Updated: 2023/11/21 01:28:48 by dbonilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_push_swap.h"

static int	ft_is_valid_char(char a)
{
	if (!(ft_digit(a) || a == ' ' || a == '-' || a == '+' ))
		return (1);
	return (0);
}

static int	ft_is_valid_num(char a, char b)
{
	if (ft_digit(a) && !(b == ' ' || b == '\0' || ft_digit(b)))
		return (1);
	return (0);
}

static int	ft_is_valid_sign(char a, char b)
{
	if ((a == '+' || a == '-' || b == '-' || b == '+') && !ft_digit(b))
		return (1);
	return (0);
}

int	ft_cheat(char **argv, int i)
{
	int	count;
	int	j;

	j = 0;
	count = 0;
	while (argv[i][j])
	{
		while (argv[i][j] == ' ' && argv[i][j] != '\0')
			j++;
		if (argv[i][j] == '\0')
			break ;
		else if (ft_is_valid_sign(argv[i][j], argv[i][j + 1]))
			return (0);
		else if (ft_is_valid_num(argv[i][j], argv[i][j + 1]))
			return (0);
		else if (ft_is_valid_char(argv[i][j]))
			return (0);
		else if (ft_digit(argv[i][j]))
			count++;
		j++;
	}
	return (count);
}

int	ft_check(int argc, char **argv)
{
	int	i;
	int	count;

	i = 1;
	count = 0;
	if (!argv[i][0] || (argv[i][0] && argv[i][0] == ' '))
	{	
		return (1);
	}
	while (++i < argc)
	{
		count = ft_cheat(argv, i);
		if (count == 0)
			return (1);
	}
	return (0);
}
