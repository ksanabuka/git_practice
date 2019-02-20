#include <unistd.h>
#include <stdio.h>

int isSpace(char c)
{
	return ((c ==32 || (c >= 9 && c<= 13))?1:0);
}
int newLen(char *s)
{
	int i = 0;
	while (s[i])
		i++;

	while(isSpace(s[i-1]) && i != 0)
		i--;
	return i;
}

int wC(char *s)
{
	int i = 0;
	int wc = 0;
	int flag = 0;
	
	while (s[i] != '\0')
	{
		while (!isSpace(s[i]) && s[i] != '\0')
		{
			flag = 1;
			i++;
		}
		(wc+=(flag == 1)?1:0);
		while (isSpace(s[i]) && s[i] != '\0')
			i++;
	}
	return wc;
}

int  printW(int pos, char *s)
{
	int flag = 0;
	while (s[pos] != '\0' && (!isSpace(s[pos])))
	{
		write(1, &s[pos],1);
		pos++;
		flag = 1;
	}
	return (( flag == 1)?1:0);
}
int main (int ac, char ** av)
{
	if (ac != 2)
	{
		write(1, "\n",1);
		return 0;
	}
	
	int pos = 0;
	int wc = 0;

	pos = newLen(av[1]) - 1;
	while (pos >= 0)
	{
		while (!isSpace (av[1][pos]) && pos >= 0)
			pos--;
		wc+= printW(pos+1, av[1]);
		if (wc != wC(av[1]))
			write(1, " ", 1);
		while (isSpace(av[1][pos]) && pos >= 0 )
			pos--;
	}
	return 0;

	//printf("%d \n", wC(av[1]));

	//printW(0,av[1]);
}
