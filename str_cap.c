#include <unistd.h>

int iS(char c)
{
	return (c == 32 || (c >= 9 && c <= 13)) ? 1 : 0;
}

int tL(char c)
{
	return (c >= 'A' && c <= 'Z') ? c + 32 : c;
}

int tU(char c)
{
	return (c >= 'a' && c <= 'z') ? c - 32 : c;
}

void sCap(char * s)
{
	char tmp;

	while (*s)
	{
	while (*s && (iS(*s)))
	{
		tmp = *s;
		write(1, &tmp, 1);
		s++;
	}


	if (*s && (!iS(*s)))
	{
		tmp = tU(*s);
		write(1, &tmp, 1);
		s++;
	}


	while  (*s && (!iS(*s)))
	{
		tmp = tL(*s);
		write(1, &tmp, 1);
		s++;
	}
	}
}

int main (int ac, char ** av)
{
	int i = 1;
	while ( i < ac )
	{
		sCap(av[i]);
		i++;
		write(1, "\n", 1);
	}
	return 0;
}



