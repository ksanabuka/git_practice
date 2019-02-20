#include<unistd.h>
#include<stdio.h>
#include<string.h>

// set n byte to value c , wich converted to unsigned char, by pointer.  

int ft_abs(int i)
{
		return ((i < 0) ? -i : i);
}

int main (int ac, char ** av)
{
 	av = 0;
	if (ac != 1)
	{
		write(1, "\n", 1);
		return 0;
	}
	
	//unsigned char arr [8];

	printf("%d\n", ft_abs(8));

	printf("%d\n", ft_abs(0));
	printf("%d\n", ft_abs(-5));

	return 0;
}

