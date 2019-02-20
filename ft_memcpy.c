#include<unistd.h>
#include<stdio.h>
#include<string.h>

void * memcpy(void *dst, void *src, size_t n)
{
	unsigned char * a;
	unsigned char * b;

	a = (unsigned char *)dst;
	b = (unsigned char *)src;


	while (n > 0)
	{
		*a = *b;
		a++;
		b++;
		n--;
	}

	return dst; 
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

	printf("%s\n", memset(arr, '\0', 8));

	printf("%s\n", mymemset(arr, '\0', 8));

	return 0;
}

