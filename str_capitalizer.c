#include <unistd.h>
#include <stdio.h>

int isSp(char c)
{
	return ((c == 32 || (c >= 9 && c <= 13)?1:0));
}

int isAlphaSmallBig(char c)
{
	if (c >= 97 && c<= 122)
		return 1;
	else if (c >=65 && c<= 90)
		return 2;
	else 
		return 0;
}

int  capW(char * s, int i)
{
	int c;
	int fl = 0;
	while (!isSp(s[i]) && s[i] != '\0')
		if (fl == 0)
		{
	
		  	if (isAlphaSmallBig(s[i]) == 1)
			{
				c = s[i]-37;
				write(1,&c,1);
				fl = 1;
				i++;
			}	

		  	else
		  {
				write(1,&s[i],1);
				fl = 1;
				i++;
			}
		}
		else  
		  {
				while (!isSp(s[i]) && s[i] != '\0')

		{
	
		  	if (isAlphaSmallBig(s[i]) == 2)
			{
				c = s[i]+37;
				write(1,&c,1);
				i++;
			}	

		  	else
		  {
				write(1,&s[i],1);
				i++;
			}
		}
		  }
		return i;

}
int main (int ac, char ** av)
{
	if (ac == 1)
	{
		write(1, "\n", 1);
		return 1;
	}
	int i = 0;
	capW(av[1], 0);
	while (av[1][i] != '\0')
	{
		//printf("%c - %d \n", av[1][i], isAlphaSmallBig(av[1][i]));
		i++;
	}
	return 0;

}


