#include<unistd.h>
#include<stdio.h>
#include<string.h>

// set n byte to 0 in string.  

void ft_bzero(void *s, size_t n)
{
	memset(s, 0, n);

}

int main (int ac, char ** av)
{
 	av = 0;
	if (ac != 1)
	{
		write(1, "\n", 1);
		return 0;
	}
	
	unsigned char arr [8];
	
	memset(arr, 65, 8);
	ft_bzero(arr, 3);
	printf("%s\n", arr);


	return 0;
}

