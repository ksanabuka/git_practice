# include <stdio.h>

char	*ft_strcat(char *d, const char *s);

int main(int ac, char **av)
{
	if (ac == 0)
		return (1);
	if (ac > 1)
		printf("%s\n", ft_strcat(av[1], av[2]));
	return (0);
}