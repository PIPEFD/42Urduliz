/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbonilla <dbonilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 15:32:18 by dbonilla          #+#    #+#             */
/*   Updated: 2023/11/21 00:47:24 by dbonilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# define MAX_INT 2147483647
# define MIN_INT -2147483648

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <sys/types.h>
# include <fcntl.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

typedef struct s_intlst
{
	int				value;
	struct s_intlst	*next;
	int				src_pos_cost;
	int				dst_pos_cost;
	unsigned int	cost;
}					t_intlst;

int				ft_atoi(const char *str);

int				ft_vabs(int n);

int				ft_max(int a, int b);

int				ft_digit(int c);

int				ft_ssign(int a, int b);

int				ft_int(char *string);

size_t			ft_putstr(char *s, int fd);

size_t			ft_putchar(char c, int fd);

size_t			ft_putnbr(int nb, int fd);

char			**ft_split(char const *s, char c);

char			*ft_strcat(char *dest, const char *src);

size_t			ft_strlcpy(char *dst, const char *src, size_t size);

size_t			ft_strlen(const char *s);

t_intlst		*ft_insert_args(int argc, char **argv);

void			ft_insert_back(t_intlst **lst, t_intlst *new);

t_intlst		*ft_insert_before(t_intlst *lst);

void			ft_free(t_intlst **lst);

int				ft_sortedr(t_intlst *lst);

int				ft_sorted(t_intlst *lst);

t_intlst		*ft_last(t_intlst *lst);

int				ft_maxval(t_intlst *lst);

int				ft_minval(t_intlst *lst);

t_intlst		*ft_new(int value);

size_t			ft_size(t_intlst *lst);

#endif