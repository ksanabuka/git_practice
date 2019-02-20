#include<unistd.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void *ft_memalloc(size_t size)
{
	void *mem;
	mem = malloc(size);
	if (!mem)
		return (NULL);
	bzero(mem, size);
	return(mem);

}

int main (int ac, char ** av)
{
 	av = 0;
	if (ac != 1)
	{
		write(1, "\n", 1);
		return 0;
	}
	
//	unsigned char arr [4] = {'a', 'b', 'c', '\0'};
	char * r;
	r = ft_memalloc(4);
	memset(r, 'a', 5);

	//printf("%s\n", memset(r, 'a', 2));

	printf("%s\n", r);

	return 0;
}

