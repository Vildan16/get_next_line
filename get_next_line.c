/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameta <ameta@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 12:20:58 by ameta             #+#    #+#             */
/*   Updated: 2021/01/19 04:33:12 by ameta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *ft_tilln(char *str)
{
    char    *tmp;
    int     n;
    
    n = 0;
    while(str[n] != '\n')
        n++;
    tmp = malloc(sizeof(char) * (n + 1));
    if (!tmp)
        return (NULL);
    tmp[n] = '\0';
    n--;
    while (n >= 0)
    {
        tmp[n] = str[n];
        n--;
    }
    return(tmp);
}

int get_next_line(int fd, char **line)
{
    int         ret;
    static char *remaining;
    char        *buf;
    int         npos;
    char        *tmp;
    
    if (fd < 0 || !line || BUFFER_SIZE <= 0)
    {
        *line = NULL;
        return (-1);
    }
    while (1)
    {
        if (!(buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
            return (-1);
        ret = read(fd, buf, BUFFER_SIZE);
        
        if (ret)
            buf[ret] = '\0';
        if (buf != NULL)
            remaining = ft_strjoin(remaining, buf);
        if (!buf[0] && remaining[0] == '\0')
        {
            *line = NULL;
            return (-1);
        }
        
        while ((npos = ft_strchr(remaining, '\n')) != -1)
        {
            tmp = ft_tilln(remaining);
            *line = NULL;
            *line = ft_strjoin(*line, tmp);
            remaining += npos + 1;
            free(tmp);
            buf = NULL;
            return (1);
        }
        buf = NULL;
        if (ret == 0)
                break ;
    }
    *line = ft_strdup("");
    
    *line = ft_strjoin(*line, remaining);
    remaining = NULL;
    free(remaining);
    
    free(buf);
    return (0);
}

