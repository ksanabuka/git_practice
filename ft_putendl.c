#include <unistd.h>

void ft_putendl(char const *s)
{
	while (*s)
	{
		write(1, *s, 1);
		s++;
	}

		write(1, "\n", 1);
}



void ft_putendl_fd(char const *s, int fd)
{
	while (*s)
	{
		write(fd, *s, 1);
		s++;
	}

		write(fd, "\n", 1);
}
