/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameta <ameta@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 12:20:58 by ameta             #+#    #+#             */
/*   Updated: 2021/01/20 17:24:46 by ameta            ###   ########.fr       */
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
    char        buf[BUFFER_SIZE + 1];
    int         npos;
    char        *tmp;
    
    if (fd < 0 || !line || BUFFER_SIZE <= 0 || read(fd, buf, 0) == -1)
    {
        if (remaining)
            free(remaining); 
        return (-1);
    }
    while (ft_strchrn(remaining) == -1 && (ret= read(fd, buf, BUFFER_SIZE)))
    {
        if (ret == -1)
        {
            if (remaining)
                free(remaining); 
            return (-1);
        }
        buf[ret] = '\0';
        remaining = ft_strjoin(remaining, buf);
        if (!remaining)
            return (-1);
    }
    if ((npos = ft_strchrn(remaining)) != -1)
    {
        *line = ft_substr(remaining, 0, npos);
        if (!line)
        {
            free(remaining);
            return (-1);
        }
        tmp = ft_substr(remaining, npos + 1, ft_strlen(remaining) - npos);
        free(remaining);
        remaining = ft_strdup(tmp);
        free(tmp);
        return (1);
    }
    if (remaining)
    {
        *line = ft_substr(remaining, 0, ft_strlen(remaining)); 
    }
    else
    {
        *line = malloc(sizeof(char));
        *line[0] = '\0';
    }
    free(remaining);
    remaining = NULL;
    return (0);   
}

