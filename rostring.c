#include <unistd.h>
#include <stdio.h>

int isSpace (char c)
{
	return ((c ==32 || (c >= 9 && c <= 13))?1:0);
}

int newLen(char * s)
{
	int i = 0;

	while (s[i] != '\0')
		i++;
	while (i != 0 && isSpace(s[i-1]))
		i--;
	return i;
}

int wC (char *s)
{
	int i, len = 0, flag;
	i = 0;
	
	while (s[i] != '\0')
	{
		flag = 0;
		while (s[i] != '\0' && (isSpace(s[i])))
			i++;

		while (s[i] != '\0' && (!isSpace(s[i])))
		{
			flag = 1;
			i++;
		}
		len+= ((flag ==1)?1:0);
	}
	return len;
}

void printFirstW(char *s)
{
	int i = 0;
	
	while (s[i] != '\0' && isSpace(s[i]))
		i++;
	while (s[i]!='\0' && !isSpace(s[i]))
	{
		write(1, &s[i], 1);
		i++;
	}
}

int main (int ac, char ** av)
{
	int flag = 0;
	int i = 0;

	if (ac < 2)
	{
		write(1, "\n", 1);
		return 1;
	}
	
	while (av[1][i] != '\0')
	{
		int wc = 0;
		while (isSpace(av[1][i]) && av[1][i] != '\0')
			i++;
		
		if  (!isSpace(av[1][i]) && av[1][i] != '\0' && flag == 0)
		{
			flag = 1;
			while (!isSpace(av[1][i]) && av[1][i] != '\0')
		{
			i++;
		}
		}
	
		while (!isSpace(av[1][i]) && av[1][i] != '\0' && flag == 1)
		{
			write(1, &av[1][i], 1);
			i++;
			wc = 1;
		}
		if (wc == 1)
			write(1, " ", 1);

	}
	
	printFirstW(av[1]);

	return 0;
}
