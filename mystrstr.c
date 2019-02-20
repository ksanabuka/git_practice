#include<unistd.h>
#include<stdio.h>

char *ft_strstr(const char *s1, const char *s2)
{

	char * a;
	char * b;


	while (*s1)
	{

	a = (char*) s1;
	b = (char *)s2;
	
	while (*b && *a == *b)
		{
			a++;
			b++;
		}
		if (*b == '\0')
			return (char *)s1;
		s1++;
	}
	return (NULL);
}

int main (int ac, char ** av)
{

	if (ac != 3)
	{
		write(1, "\n", 1);
		return 0;
	}

	printf("%s\n", ft_strstr(av[1], av[2]));
	return 0;
}

