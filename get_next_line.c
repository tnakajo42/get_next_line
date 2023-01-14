/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakajo <tnakajo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 18:55:06 by tnakajo           #+#    #+#             */
/*   Updated: 2023/01/14 20:12:44 by tnakajo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	ssize_t		n;
	char		*str_rtrn;
	char		*str_buff;
	char		*str_temp;
	static char	*str_line;

	if (fd == -1 || BUFFER_SIZE < 1)
	{
		if (str_line)
		{
			free (str_line);
			str_line = NULL;
		}
		return (NULL);
	}
	str_buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!str_buff)
		return (NULL);
	n = read(fd, str_buff, BUFFER_SIZE);
	if (n == -1)
	{
		free (str_buff);
		if (str_line)
		{
			free (str_line);
			str_line = NULL;
		}
		return (NULL);
	}
	str_buff[n] = '\0';
	if (n == 0)
	{
		free (str_buff);
		if (ft_str_len(str_line))
		{
			if (ft_str_char(str_line, '\n'))
			{
				str_temp = ft_str_dup(str_line);
				str_rtrn = ft_str_dup_b(str_temp, '\n');
				str_line = ft_str_dup_a(str_temp, '\n');
				free (str_temp);
				return (str_rtrn);
			}
			else
			{
				str_rtrn = ft_str_dup_b(str_line, '\0');
				free (str_line);
				str_line = NULL;
				return (str_rtrn);
			}
		}
		else
		{
			free (str_line);
			str_line = NULL;
			return (str_line);
		}
	}
	else
	{
		// str_temp = ft_str_dup(str_line);
		str_temp = str_line;
		str_line = ft_str_cat(str_temp, str_buff);
		free(str_temp);
		free(str_buff);
		printf("-->%s<--\n", str_line);
		if (ft_str_char(str_line, '\n'))
		{
			str_temp = ft_str_dup(str_line);
			str_rtrn = ft_str_dup_b(str_temp, '\n');
			str_line = ft_str_dup_a(str_temp, '\n');
			free (str_temp);
			return (str_rtrn);
		}
		else
			return (get_next_line(fd));
	}
}

/* char *test(int fd)
{
	ssize_t		n;
	char		*str_rtrn;
	char		*str_buff;
	char		*str_temp;
	static char	*str_line;

	if (fd == -1 || BUFFER_SIZE < 1)
	{
		if (str_line)
			free (str_line);
		return (NULL);
	}
	str_buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!str_buff)
		return (NULL);
	n = read(fd, str_buff, BUFFER_SIZE);
	
	str_temp = str_line;
	str_line = ft_str_cat(str_temp, str_buff);
	free(str_temp);
	free(str_buff);
	if (ft_str_char(str_line, '\n'))
	{
		str_temp = str_line;
		str_rtrn = ft_str_dup_b(str_temp, '\n');
		str_line = ft_str_dup_a(str_temp, '\n');
		free (str_temp);
		// free (str_line);
		return (str_rtrn);
	}
	else
		return (test(fd));
} */



/* char	*get_next_line(int fd)
{
	char	*a;

	a = (char *)malloc(5 * sizeof(char));
	a = "test";
	free (a);
	return (NULL);
} */
