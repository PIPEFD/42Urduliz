/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   .main.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbonilla <dbonilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 11:51:57 by dbonilla          #+#    #+#             */
/*   Updated: 2023/06/13 08:00:36 by dbonilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*line;
	int		i;

	fd = open("text.txt", O_RDONLY);
	line = "";
	i = 1;
	while (i != 3)
	{
		line = get_next_line(fd);
		printf = ("text.txt", line);
		if (!line)
		free (line);
		i++;
	}
	close (fd);
}
