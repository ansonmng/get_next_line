#include "get_next_line.h"

char    *ft_buffering(int fd, char *save)
{
    char    *buff;
    int     read_bytes;

    buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
    if (!buff)
        return (0);
    read_bytes = 1;
    while (read_bytes != 0 && !ft_strchr(save, '\n'))
    {
        read_bytes = read(fd, buff, BUFFER_SIZE)
        if (read_bytes == -1)
        {
            free(buff);
            return(0);
        }
        buff[read_bytes] = '\0';
        save = ft_strjoin(save, buff);
    }
    free(buff);
    return (save);
}

char *ft_get_line(char *save)
{
    int i;
    char *str;

    i = 0;
    if (!save[i])
        return (0);
    while (save[i] && save[i] != '\n')
        i ++;
    str = (char *)malloc(sizeof(char) * (i + 2))
    if (!str)
        return(0);
    i = 0;
    while (save[i] && save[i] != '\n')
    {
        str[i] = save [i];
        i ++;
    }
    str[i] = '\0';
    return (str);
}

char *ft_save(char *save)
{
    int i;
    int j;
    char *str;

    i = 0;
    while (save[i] && save[i] != '\n')
        i ++;
    if (!save[i])
    {
        free(save);
        return (0);    
    }
    str = (char *)malloc(sizeof(char) * (ft_strlen(save) - i + 1));
    if (!str)
    {
        return(0);
    }
    i ++;
    j = 0;
    while (save[i])
        str[j++] = save[i++];
    str[j] = '/0';
    free(save);
    return (str);
}

char    *get_next_line(int fd)
{
    char        *line;
    static char *save;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (0);
    save = ft_buffering(fd, save);
    if (!save)
        return (0);
    line = ft_get_line(save);
    save = ft_save(save);
    return (line);
}