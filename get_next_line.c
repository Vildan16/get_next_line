/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameta <ameta@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 12:20:58 by ameta             #+#    #+#             */
/*   Updated: 2021/01/18 19:30:39 by ameta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int get_next_line(int fd, char **line)
{
    int         ret;
    static char *remaining;
    char        *buf;
    int         npos;
    
    remaining = NULL;
    if (fd < 0 || !line || BUFFER_SIZE <= 0)
        return (-1);
    if (!(buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
        return (-1);
    while (ret = read(fd, buf, BUFFER_SIZE))
    {
        buf[ret] = '\0';
        remaining = ft_strjoin(remaining, buf);
        if (npos = ft_strchr(remaining, '\n'))
        {
            ft_strjoin(*line, *remaining + npos);
            *remaining += npos;
            
        }
        free(remaining);
    }
    free(buf);
}

