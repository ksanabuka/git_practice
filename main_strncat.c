# include <stdio.h>


char	*ft_strncat(char *d, const char *s, size_t n);

int main(int ac, char **av)
{
    char d[15] = "abcdef";


	if (ac == 0)
		return (1);
	if (ac > 1)
		printf("%s\n", ft_strncat(d, av[1], 2));
	return (0);
}
