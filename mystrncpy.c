#include<unistd.h>
#include<stdio.h>
#include<string.h>

// ./a.out 'abcd' 'gef' 3 --> gefd
//./a.out 'abcde' 'gef' 4 --> gef\0\0\0
// ./a.out 'abcde' 'gef' 1 --> gbcde
// abort      ./a.out 'ab' 'gefgi', 4
// function writes most of n of src into dest, if n > src , it adds \0 to the left of dest.
// error if n > dest;
//
char *mystrncpy(char *d, const char *s, size_t n)
{
	size_t i = 0;

	char * r;

	r = (char*) d;


	while (i < n && *s)
	{
		*d = *s;
		i++;
	}

	while (i < n && *d)
	{
		*d = '\0';
		i++;
	}

	return r;
}


int main (int ac, char ** av)
{

	if (ac != 3)
	{
		write(1, "\n", 1);
		return 0;
	}

	printf("%s\n", strncpy(av[1], av[2], 4));
	printf("%s\n", mystrncpy(av[1], av[2], 4));
	return 0;
}

