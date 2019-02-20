#include <unistd.h>

void	print_memory(const void *addr, size_t size)
{
	size_t			i;
	size_t 			j;
	unsigned char	*p;
	char 			*str;

	str = "0123456789abcdef";
	p = (unsigned char *)addr;
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < 16 && i + j < size)
		{
			write(1, &str[(*(p + i + j)/16) % 16], 1);
			write(1, &str[*(p + i + j) % 16], 1);
			if (j % 2)
				write(1, " ", 1);
			j += 1;
		}
		while (j < 16)
		{
			write(1, "  ", 2);
			if (j % 2)
				write(1, " ", 1);
			j++;
		}
		j = 0;
		while (j < 16 && i + j < size)
		{
			if (*(p + i + j) >= 32 && *(p + i + j) < 127)
				write(1, p + i + j, 1);
			else
				write(1, ".", 1);
			j += 1;
		}
		write(1, "\n", 1);
		i += 16;
	}
}

int main (int ac, char ** av)
{
	av = 0;
	// unsigned char s [] = "abcd";
	//int	tab[30] = {65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90};
	//char str [20] = "1234567890";
	//char str [1] = "";
	char str [1024] = "as it is known since. This code\narises from reorder and expand the set of symbols and characters already used in telegraphy at that time by the Bell company.At first only included capital letters and numbers , but in 1967 was added the lowercase letters and some control characters, forming what is known as US-ASCII, ie the characters 0 through 127.So with this set of only 128 characters was published in 1967 as standard, containing all you need to write in English language.In 1981, IBM developed an extension of 8-bit ASCII code, called";


	if (ac == 1)
	{
		size_t size = 61;
		print_memory((unsigned char *) str, size);
		//print16ascii((unsigned char *) tab);


	}
	return 0;
}