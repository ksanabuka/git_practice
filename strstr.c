#include<unistd.h>
#include<stdio.h>
# include<stdlib.h>

int mylen(char *s)
{
	int i = 0;
	while(s[i])
		i++;
	return i;
}

int isIn(char c, char *s,  int start, int end)
{
	if (start < 0)
		return -1;
	if (!c)
		return -1;

	while (s[start] != '\0' || start <= end )
	{
		if (c == s[start])
			return start;
		else
			start++;

	}
	return -1;
}

char *mystrstr(char *h, char *n)
{
	char * r;
	int i = 0;
	int j = 0;
	int good = 0;
	int first = 0;



	if (!mylen(n))
	{
		r = h;
		return r;
	}


	while (h[j] && n[i])
	{
		if (isIn(n[i], h, j, mylen(h) - 1 ) == -1)
			return (NULL);
		
		while  ((isIn(n[i], h, j, mylen(h) - 1 ) != -1) && n[i] && h[j])
		{
			i++;
			j =  (isIn(n[i], h, j, mylen(h) - 1 ));
			good++;
			first = (first == 0) ? j : first;
		}

		if (good != mylen(n))
		{
			first = 0;
			i = 0;
			j =  (isIn(n[i], h, j, mylen(h) - 1 ) + 1);
		}	
	}


		if (good == mylen(n))
		{
			r = &h[first];
			return r;
		}
	
	//	else 
	//	{	
	//	r = NULL;
	//	return (r);
	//	}	
}	


int main (int ac, char ** av)
{

	if (ac != 3)
	{
		write(1, "\n", 1);
		return 0;
	}
	
	printf("%s\n", mystrstr(av[1], av[2]));

//	while (av[1][i] != '\0')
//	{
//	printf("%c is at pos %d \n", av[1][i], isCharInStrRange(av[1][i], av[2], 0, mylen(av[2] - 1)));
//		i++;	
//	}
	return 0;
}

