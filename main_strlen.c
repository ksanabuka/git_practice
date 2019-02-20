# include <stdio.h>

size_t	ft_strlen(const char *s);

int main(int ac, char **av)
{
	if (ac == 0)
		return (1);
	if (ac > 1)
		printf("%zu\n", ft_strlen(av[1]));
	return (0);
}