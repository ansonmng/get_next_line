/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nansonm <ansonmng@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 16:18:12 by nansonm           #+#    #+#             */
/*   Updated: 2022/03/01 16:23:13 by nansonm          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "get_next_line.h"

static void	reading(int fd, char *buff, char **str)
{
	int		i;
	char	*tmp;

	i = 0;
	if (!*str || !ft_strchr(*str, '\n'))
	{
		i = read(fd, buff, BUFFER_SIZE);
		while (i > 0)
		{
			buff[i] = '\0';
			if (!*str)
				*str = ft_strdup("");
			tmp = *str;
			*str = ft_strjoin(*str, buff);
			free (tmp);
			if (ft_strchr(buff, '\n'))
				break ;
			i = read(fd, buff, BUFFER_SIZE);
		}
	}
	free(buff);
}

static char	*process(char **str)
{
	char	*tmp;
	char	*save;

	if (!*str)
		return (NULL);
	if (!ft_strchr(*str, '\n'))
	{
		save = ft_substr(*str, 0, ft_strlen(*str));
		free(*str);
		*str = NULL;
		return (save);
	}
	save = ft_substr(*str, 0, ft_strlen(*str)
			- ft_strlen(ft_strchr(*str, '\n')) + 1);
	tmp = *str;
	*str = ft_substr(ft_strchr(*str, '\n'), 1,
			ft_strlen(ft_strchr(*str, '\n')) - 1);
	free(tmp);
	if (!**str)
	{	
		free(*str);
		*str = NULL;
	}
	return (save);
}

char	*get_next_line(int fd)
{
	char		*buff;
	static char	*str;

	buff = malloc(sizeof(char) * ((BUFFER_SIZE) + 1));
	if (!buff)
		return (0);
	if (BUFFER_SIZE < 1 || fd == -1 || read(fd, buff, 0) == -1)
	{
		free(buff);
		return (0);
	}
	reading(fd, buff, &str);
	return (process(&str));
}
