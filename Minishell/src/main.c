/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 10:45:53 by codespace         #+#    #+#             */
/*   Updated: 2024/04/15 09:10:57 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/minishell.h"



t_data	*g_data;


// Function to import the environment variables
static void ft_import_envp(t_data *data, char **envp)
{
	int i;
	
}


// Function to initialize the data structure
t_data *ft_init_data(char **envp)
{
	(void)envp;
	
	t_data *data;
	// Allocating memory for the data structure
	data = (t_data *)malloc(sizeof(t_data));
	// Verifies if the allocation was successful
	if (!data)
		perror("Error: Malloc failed.\n");
	// Initializes the data structure
	data->input = NULL;
	data->prompt = NULL;
	// function to import the environment variables
	ft_import_envp(data, envp);
	return(data);
}
 
 

int	main(int argc, char **argv, char **envp)
{
	(void)argv;
	(void)envp;
	if (argc != 1)
			perror("Error: No arguments are allowed.\n");
	g_data =ft_init_data(envp);
	printf("g_data->input = %s\n", g_data->input);
	if (g_data->prompt != NULL)
		free (g_data->prompt);
	// g_data->prompt = ft_gen_prompt(g_data);	
	while (1)
		g_data->input = readline(PROMPT);
		

}