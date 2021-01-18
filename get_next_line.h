/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameta <ameta@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 12:20:07 by ameta             #+#    #+#             */
/*   Updated: 2021/01/19 01:42:00 by ameta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2
# endif

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h> //remove

int get_next_line(int fd, char **line);
char	*ft_strdup(const char *s1);
int     ft_strchr(const char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
char    *ft_tilln(char *str);

#endif
