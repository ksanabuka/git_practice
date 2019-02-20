#include <unistd.h>
#include <stdio.h>
int isSpace( char c)
{
	return 	((c == 32) || (c >= 9 && c <= 13)) ? 1 : 0;
}

int mylen(char *s)
{
	int i = 0;

	while(s[i])
	{
		i++;
	}

	return i;
}

int newLen(char *s)
{
	int i = mylen(s);
	while(i > -1 && isSpace(s[i - 1]))
	   i--;

	return i;	
}

int wC(char *s)
{
	unsigned int wc = 0;
	int i = 0;
	int flag = 0;
	while (( i < newLen(s)) && s[i])
	{
		flag = 0;
		while ( isSpace(s[i]) && i < newLen(s) && s[i])
			i++;

		while ( !isSpace(s[i]) && i < newLen(s) && s[i])
		{
			flag = 1;
			i++;
		}
		wc += (flag == 1) ? 1 : 0;
	}
	
	
	return (int) wc;

}

int main (int ac, char ** av)
{
	if (ac != 2)
	{
		write(1, "\n", 1);
		return 0;
	}
	//printf("%d\n", wC(av[1]));

	int wc = wC(av[1]);
	int nL	= newLen(av[1]);
	int i = 0;
	//print 1word
//	while ( av[1][i] != '\0' && i < nL)
//	{
//		
//	while ( isSpace(av[1][i]) && av[1][i] != '\0' && i < nL)
//		i++;
//
//	while ( !isSpace(av[1][i]) && av[1][i] != '\0' && i < nL)
//	{
//		write(1, &av[1][i], 1);
//		wc = 1;
//		i++;
//	}
//	write(1, "\n", 1);
//	return 0;
//	}
	//print last word 
	i = 0;
	int flag;
	wc = 0;	
	while ( av[1][i] != '\0' && i < nL)
	{
		
	 flag = 0;
	while ( isSpace(av[1][i]) && av[1][i] != '\0' && i < nL)
		i++;

	if (wc  == wC(av[1]) - 1)
	{
	
	while ( isSpace(av[1][i]) && av[1][i] != '\0' && i < nL)
		i++;

	while (!isSpace(av[1][i]) && av[1][i] != '\0' && i < nL)
	{
		write(1, &av[1][i], 1);	
		i++;
	}
	}
	
	while (!isSpace(av[1][i]) && av[1][i] != '\0' && i < nL)
	{	
		i++;
		flag = 1;
	}
	wc+=(flag == 1) ? 1 : 0;

	}

	write(1, "\n", 1);
	return 0;
}
