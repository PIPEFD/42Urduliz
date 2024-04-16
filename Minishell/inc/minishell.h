/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 19:02:27 by codespace         #+#    #+#             */
/*   Updated: 2024/04/14 13:58:09 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
// # include "../libft/inc/libft.h"
# include <readline/readline.h>
# include <readline/history.h>
# include <fcntl.h>
# include <dirent.h>
# include <sys/wait.h>
# include <signal.h>
# include <errno.h>
# include <stdio.h>
# include <stdlib.h>


# define PROMPT	 "\033[0;92m >>HELLO_WORD$ \033[0;39m"


typedef struct s_data
{
	char	*input;
	// char	*ex_input;
	char	*prompt;
	// int		baseline_infd;
	// int		baseline_outfd;
	// char	**custom_envp;
	// // t_vars	*vars;
	// // t_cmd	*cmd;
}			t_data;

// int main(int argc, char **argv, char **envp);
t_data *ft_init_data(char **envp);


#endif