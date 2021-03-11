#include <stdlib.h>
#include <unistd.h>

int     ft_strlen(char *s)
{
    int i = 0;

    if (!s)
        return (0);
    while (s[i])
        i++;
    return (i);
}

int     ft_strchrn(char *s)
{
    int i = 0;

    if (!s)
        return (-1);
    while (s[i])
    {
        if (s[i] == '\n')
            return (i);
        i++;
    }
    return (-1);
}

char    *ft_strdup(char *s)
{
    int i = 0;
    char *res;

    if (!s)
        return (NULL);
    res = malloc(sizeof(char) * (ft_strlen(s) + 1));
    if (!res)
        return (NULL);
    while (s[i])
    {
        res[i] = s[i];
        i++;
    }
    res[i] = '\0';
    return (res);
}

char    *ft_substr(char *s, int start, int size)
{
    int i = 0;
    char *res;
    int slen;

    if (!s)
        return (NULL);
    res = malloc(sizeof(char) * (size + 1));
    if (!res)
        return (NULL);
    slen = ft_strlen(s);
    while (s[start] && start < slen && size)
    {
        res[i] = s[start];
        i++;
        start++;
        size--;
    }
    res[i] = '\0';
    return (res);
}

char    *ft_strjoin(char *s1, char *s2)
{
    int i = 0;
    int j = 0;
    char *res;
    int slen1;
    int slen2;

    if (!s1 && !s2)
        return (NULL);
    slen1 = ft_strlen(s1);
    slen2 = ft_strlen(s2);
    res = malloc(sizeof(char) * (slen1 + slen2 + 1));
    if (!res)
        return (NULL);
    while (i < slen1)
    {
        res[i] = s1[i];
        i++;
    }
    while (j < slen2)
    {
        res[i] = s2[j];
        i++;
        j++;
    }
    res[i] = '\0';
    return (res);
}

int     ft_retline(char **line, char **rem, int npos)
{
    char *tmp;

    *line = ft_substr(*rem, 0, npos);
    if (!line)
    {
        free(*rem);
        return (0);
    }
    tmp = ft_substr(*rem, npos + 1, ft_strlen(*rem) - npos);
    free(*rem);
    if (!tmp)
        return (0);
    *rem = ft_strdup(tmp);
    free(tmp);
    if (!(*rem))
        return (0);
    return (1);
}

int     ft_fillrem(char **rem, int ret, char **buf)
{
    char *tmp;

    if (ret == -1)
    {
        *rem != NULL ? free(*rem) : 0;
        free(*buf);
    }
    (*buf)[ret] = '\0';
    tmp = ft_strjoin(*rem, *buf);
    if (!tmp)
        return (0);
    free(*rem);
    *rem = ft_strdup(tmp);
    free(tmp);
    if (!(*rem))
        return (0);
    return (1);
}

int     ft_get_next_line(char **line)
{
    static char *rem;
    char *buf;
    int ret;
    int npos;

    buf = malloc(sizeof(char) * 43);
    if (!buf || !line)
    {
        buf != NULL ? free(buf) : 0;
        rem != NULL ? free(rem) : 0;
        return (-1);
    }
    while (ft_strchrn(rem) == -1 && (ret = read(0, buf, 42)))
    {
        if (!ft_fillrem(&rem, ret, &buf))
            return (-1);
    }
    buf ? free(buf) : 0;
    if ((npos = ft_strchrn(rem)) != -1)
        return (ft_retline(line, &rem, npos) ? 1 : -1);
    *line = (rem ? ft_substr(rem, 0, ft_strlen(rem)) : ft_strdup(""));
    free(rem);
    rem = NULL;
    return (0);
}

#include <stdio.h>

int     main(void)
{
    int i = 0;
    char *line;

    while ((i = ft_get_next_line(&line)))
    {
        printf("i = %d %s\n", i, line);
        free(line);
    }
    printf("i = %d %s\n", i, line);
    free(line);
    return (0);   
}