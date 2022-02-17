#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "get_next_line.h"

#ifndef O_RDONLY
# define O_RDONLY 0
#endif

#ifndef FD_MAX
# define FD_MAX 1024 
#endif

#define GNL_CALL 10000
#define THEN_DIFF 1 

int	main(int ac, char **av)
{
	char			*line;
	int				fd;
	int				i;

	(void)ac;
	fd = open(av[1], O_RDONLY);
	if (!fd)
		return (1);
	i = 0;
	while (i++ < GNL_CALL)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (THEN_DIFF)
			printf("%s", line);
		else
			printf("line [%02d]: %s", i, line);
		free(line);
	}
	close(fd);
	return (0);
}