/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_args.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbonilla <dbonilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 22:14:41 by codespace         #+#    #+#             */
/*   Updated: 2023/11/20 21:36:01 by dbonilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_push_swap.h"

static int	ft_size_input(int argc, char ***argv)
{
	int	length;
	int	i;

	i = 0;
	length = 0;
	while (i < argc)
		length += ft_strlen(*(*(argv) + i++)) + 1;
	return (length);
}

static int	ft_countarg(char **tab)
{
	int	i;

	i = 0;
	while (*(tab + i))
		i++;
	return (i);
}

int	ft_args(int argc, char ***argv)
{
	char	*str;
	char	**arg_list;
	int		i;
	int		flag;

	str = (char *)calloc(sizeof(char), (ft_size_input(argc, argv) + 1));
	if (!str)
		return (0);
	i = 0;
	flag = 1;
	while (i < argc)
	{
		if (flag == 0)
		{
			str = ft_strcat(str, " ");
			flag = 1;
			continue ;
		}
		str = ft_strcat(str, *(*(argv) + i++));
		flag = 0;
	}
	arg_list = ft_split(str, ' ');
	free(str);
	*argv = arg_list;
	return (ft_countarg(arg_list));
}
