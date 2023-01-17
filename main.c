/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakajo <tnakajo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 20:03:11 by tnakajo           #+#    #+#             */
/*   Updated: 2023/01/17 22:13:43 by tnakajo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include "get_next_line.h"
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

	path = "multiple_nl.txt";
	fd = open(path, O_RDONLY);
	i = 0;
	while (i < 6) // <-- number of loops
	{
		i++;
		// str = test(fd);
		// str = get_next_line(fd);
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
	close(fd);
	return (0);
} */

/* 
void	read_and_print_100(int fd)
{
	char	buf[100];	// store the read characters
	int	nb_read;	// store read's return value


//	Read 100 characters from the file descriptor
	nb_read = read(fd, buf, 100);
//	Stop everything in case of error
	if (nb_read == -1)
	{
		printf("Read error!\n");
		return ;
	}
//	Add \0 to the end of the buffer
	buf[nb_read] = '\0';
//	Print the file descriptor and then the buffer contents
	printf("\e[36mfd %d : [\e[0m%s\e[36m]\e[0m\n", fd, buf);
	return ;
} */

/* int	main(void)
{
	int	fd;	// file descriptor to read

//	Open the cat.txt file in read only mode
	fd = open("cat.txt", O_RDONLY);
	if (fd == -1)
		return (1);
//	Print the first 100 characters from the file descriptor
	read_and_print_100(fd);
//	Reset offset to the beginning of the file
	lseek(fd, 0, SEEK_SET);
	read_and_print_100(fd);
//	Set the offset to 4 characters from the beginning of the file
	lseek(fd, 4, SEEK_SET);
	read_and_print_100(fd);
//	Set the offset to 1 character from current position
	lseek(fd, 1, SEEK_CUR);
	read_and_print_100(fd);
//	Set offset to be at the end of the file
	lseek(fd, 0, SEEK_END);
	read_and_print_100(fd);
//	Close opened file descriptor
	close(fd);
	return (0);
} */