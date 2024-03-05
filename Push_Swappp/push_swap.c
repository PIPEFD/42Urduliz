/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbonilla <dbonilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 20:37:03 by codespace         #+#    #+#             */
/*   Updated: 2023/11/20 23:23:32 by dbonilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_push_swap.h"

static int	ft_same(int argc, char **argv, int i)
{
	int	j;
	int	num;

	num = ft_atoi (*(argv + i));
	j = i + 1;
	while (j < argc)
	{
		if (ft_atoi(*(argv + j)) == num)
			return (1);
		j++;
	}
	return (0);
}

static int	ft_errors(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!ft_int(*(argv + i)) || ft_same(argc, argv, i))
		{
			ft_putstr ("Error\n", 2);
			return (1);
		}	
		i++;
	}
	return (0);
}

int	ft_free_args(int i, char ***argv)
{
	if (i != 0)
	{
		while (i--)
			free(*(*(argv) + i));
		free (*argv);
	}
	return (2);
}

int	main(int argc, char **argv)
{
	t_intlst	*a;
	t_intlst	*b;

	if (argc > 1)
	{
		if (argc == 1 || argc == 0 || ft_check((argc), argv) == 1)
			return (ft_putstr("Error\n", 2));
		argc = ft_args(argc, &argv);
		if (argc == 0)
			return (ft_free_args(argc, &argv));
		if (ft_errors(argc, argv))
			return (ft_free_args(argc, &argv));
		a = ft_insert_args(argc, argv);
		b = NULL;
		ft_size_argv(&a, &b, argc - 1);
		ft_free(&a);
		ft_free(&b);
		ft_free_args(argc + 1, &argv);
	}
	return (0);
}
