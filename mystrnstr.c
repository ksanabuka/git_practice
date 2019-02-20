#include<unistd.h>
#include<stdio.h>
#include<string.h>

//./a.out 'abcd' 'ab' 2 -->abcd

char * mystrnstr (const char *d, const char *n, size_t nbr)
{
	char * a;
	char * b;
	size_t i;

	i = 0;

	if (!*n)
			return (char*)d;

	while (*d)
	{	
		a = (char *)d;
		b = (char *)n;

		while (i < nbr && *b && *b == *a)
		{
			*a = *b;
			i++;
			a++;
			b++;
		}
		if (i == nbr)
			return (char*)d;
		i++;
		d++;
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
	
	printf("%s\n", strnstr(av[1], av[2], 2));

	printf("%s\n", mystrnstr(av[1], av[2], 2));

	return 0;
}

