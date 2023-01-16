/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakajo <tnakajo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 18:58:45 by tnakajo           #+#    #+#             */
/*   Updated: 2023/01/16 18:27:07 by tnakajo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

char	*get_next_line(int fd);
int		ft_str_len(char *str);
int		ft_str_char(char *str, int c);
char	*ft_str_dup_b(char *str, int c);
char	*ft_str_dup_a(char *str, int c);
char	*ft_str_cat(char *str_line, char *str_buff);
void	ft_str_cat_sub(char *dest, char *src, int start);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10000000
# endif

#endif