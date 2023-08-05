/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 11:44:37 by codespace         #+#    #+#             */
/*   Updated: 2023/07/20 14:00:08 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// #include "../libft/libft.h"

typedef struct s_stack
{
	int				content;
	unsigned int	index;
	struct s_stack	*next;
}	t_stack;

/* ERRORES */
int		ft_arg_nbr_err(char *s);
int		ft_stack_duplicate_err(t_stack **stack);
int		ft_int_limit_error(char *str);

/*SORT*/

void	ft_radix_sort(t_stack **stack_a, t_stack **stack_b, int size);
void	ft_sort(t_stack **stack_a, t_stack **stack_b, int size);


/*OPERATIONS*/

void	ft_swap(t_stack stack, char id);
void	ft_swapswap(t_stack **stack_a, t_stack **stack_b);
void	ft_push(t_stack **stack_a, t_stack **stack_b, char id);
void	ft_rotate(t_stack **stack, char id);
void	ft_rotaterotate(t_stack **stack_a, t_stack **stack_b);
void	ft_reverse_rotate(t_stack **stack, char id);
void	ft_rr_rotate(t_stack **stack_a, t_stack **stack_b);

/* STACK UTILITIES*/

t_stack	*ft_stack_get_last(t_stack **stack);
t_stack	*ft_stack_get_last_to_one(t_stack **stack);
t_stack *ft_create_stack_elmt(int nb);
void	ft_stack_push(t_stack **stack, t_stack *new);
t_stack	*ft_get_max(t_stack **stack);
int		ft_stack_is_sorted(t_stack **stack);
t_stack	**ft_initialize_stack(int arhc, char **argv, int is_reorganize);
t_stack *ft_get_min(t_stack **stack, long limit);
void	ft_give_inves(t_stack **stack, int size);
void	ft_free(t_stack ***stack, char ***argv, int argc, int is_reorganize);

#endif


