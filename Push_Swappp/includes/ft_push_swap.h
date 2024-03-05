/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbonilla <dbonilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 18:55:19 by codespace         #+#    #+#             */
/*   Updated: 2023/11/20 19:21:31 by dbonilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include "../libft/inc/libft.h"

void			ft_pa(t_intlst **a, t_intlst **b);
void			ft_pb(t_intlst **a, t_intlst **b);
void			ft_sa(t_intlst **a);
void			ft_sb(t_intlst **b);
void			ft_ss(t_intlst **a, t_intlst **b);
void			ft_ra(t_intlst **a);
void			ft_rb(t_intlst **b);
void			ft_rr(t_intlst **a, t_intlst **b);
void			ft_rra(t_intlst **a);
void			ft_rrb(t_intlst **b);
void			ft_rrr(t_intlst **a, t_intlst **b);
int				ft_args(int argc, char ***argv);
void			ft_rotate(t_intlst **lst);
void			ft_rotater(t_intlst **lst);
void			ft_rotates(t_intlst **a, t_intlst **b, int cos_a, int cos_b);
void			ft_rotate_sa(t_intlst **a, int cost);
void			ft_rotate_sb(t_intlst **b, int cost);
void			ft_size_argv(t_intlst **a, t_intlst **b, int n);
void			ft_size_2(t_intlst **lst);
void			ft_size_3(t_intlst **lst);
void			ft_size_5(t_intlst **a, t_intlst **b, int n);
void			ft_size_big(t_intlst **a, t_intlst **b, int n);
void			ft_sizer_2(t_intlst **lst);
void			ft_sizer_3(t_intlst **lst);
unsigned int	ft_derive_cost(t_intlst **src, t_intlst **dst);
int				ft_get_dstcost_max_first(t_intlst *lst);
void			ft_push(t_intlst **src, t_intlst **dst);
void			ft_swap(t_intlst **lst);
int				ft_cheat(char **argv, int i);
int				ft_check(int argc, char **argv);
int				ft_free_args(int i, char ***argv);

#endif
