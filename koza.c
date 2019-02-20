#include<unistd.h>
#include<stdio.h>
#include<string.h>

// set n byte to value c , wich converted to unsigned char, by pointer.  

void *mymemset (void *b, int c, size_t len)
{
	unsigned char * r;

	r = (unsigned char *) b;
	
		while (len--)
		{
			*r = (unsigned char) c;
			r++;
		}

	return b;
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

