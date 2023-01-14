/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakajo <tnakajo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 20:03:11 by tnakajo           #+#    #+#             */
/*   Updated: 2023/01/14 20:03:47 by tnakajo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	printf("|-- TEST -->\n");

	printf("|-- get_next_line -->\n");
	int		i;
	int		fd;
	char	*str;
	char	*path;

	path = "hello.txt";
	fd = open(path, O_RDONLY);
	i = 0;
	while (i < 4) // <-- number of loops
	{
		i++;
		// str = test(fd);
		str = get_next_line(fd);
		printf("%d. %s", i, str);
		free(str);
	}
	// str = get_next_line(fd);
	// 	free(str);
	// str = test(-1);
	printf("<-- get_next_line --|\n");

	// int		i;

	// i = 0;
	// i++;
	// get_next_line(2);
	// get_next_line(2);
	// get_next_line(2);
	// get_next_line(2);
	// get_next_line(2);
	// printf("%d\n", i);
	// printf("%d\n", BUFFER_SIZE);
	return (0);
}