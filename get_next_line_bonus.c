/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakajo <tnakajo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 19:09:08 by tnakajo           #+#    #+#             */
/*   Updated: 2023/01/17 22:36:08 by tnakajo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	ssize_t		nb_read;
	char		*str_buff;
	static char	*str_line[1048576];

	if (fd == -1 || BUFFER_SIZE < 1)
		return (NULL);
	str_buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!str_buff)
	{
		ft_str_free(&str_line[fd]);
		return (NULL);
	}
	nb_read = read(fd, str_buff, BUFFER_SIZE);
	if (nb_read == -1)
	{
		free (str_buff);
		ft_str_free(&(str_line[fd]));
		return (NULL);
	}
	str_buff[nb_read] = '\0';
	if (nb_read == 0)
		return (get_next_line_sub(&(str_line[fd]), &str_buff));
	return (get_next_line_with_n(&(str_line[fd]), &str_buff, fd));
}

char	*get_next_line_sub(char **str_line, char **str_buff)
{
	char	*str_temp;
	char	*str_rtrn;

	free (*str_buff);
	if (ft_str_len(*str_line))
	{
		if (ft_str_char(*str_line, '\n'))
		{
			str_temp = *str_line;
			str_rtrn = ft_str_dup_b(str_temp, '\n');
			*str_line = ft_str_dup_a(str_temp, '\n');
			free (str_temp);
			return (str_rtrn);
		}
		str_rtrn = ft_str_dup_b(*str_line, '\0');
		free (*str_line);
		*str_line = NULL;
		return (str_rtrn);
	}
	free (*str_line);
	*str_line = NULL;
	return (*str_line);
}

char	*get_next_line_with_n(char **str_line, char **str_buff, int fd)
{
	char	*str_temp;
	char	*str_rtrn;

	str_temp = *str_line;
	*str_line = ft_str_cat(str_temp, *str_buff);
	free(str_temp);
	free(*str_buff);
	if (ft_str_char(*str_line, '\n'))
	{
		str_temp = *str_line;
		str_rtrn = ft_str_dup_b(str_temp, '\n');
		*str_line = ft_str_dup_a(str_temp, '\n');
		free (str_temp);
		return (str_rtrn);
	}
	return (get_next_line(fd));
}

void	ft_str_free(char **str)
{
	if (*str)
	{
		free (*str);
		*str = NULL;
	}
}

int	ft_str_len(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}
