#include "get_next_line.h"
#include <stdlib.h>

size_t	ft_strlen(const char *str)
{
	size_t	c;

	c = 0;
	if (!str)
		return (0);
	while (str[c] != '\0')
		c++;
	return (c);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s != (unsigned char)c)
		if (!*s++)
			return (0);
	return ((char *)s);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*ret;
	char	*tmp;
	size_t	i;

	ret = malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (0);
	tmp = (char *)s + start;
	i = 0;
	while (*tmp && i < len)
		ret[i++] = *tmp++;
	ret[i] = 0;
	return (ret);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	char	*str;

	str = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (*s1)
		str[i++] = *s1++;
	while (*s2)
		str[i++] = *s2++;
	str[i] = '\0';
	return (str);
}

char	*ft_strdup(const char *s1)
{
	char	*cpy;
	char	*save;
	size_t	len;

	len = ft_strlen(s1);
	cpy = malloc(len + 1);
	if (!cpy)
		return (NULL);
	save = cpy;
	while (*s1)
		*cpy++ = *s1++;
	*cpy = '\0';
	return (save);
}