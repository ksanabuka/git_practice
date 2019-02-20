#include <unistd.h>
#include <stdlib.h>

// Write a function that takes (const void *addr, size_t size), and displays the
// memory as in the example.

// Your function must be declared as follows:

// void	print_memory(const void *addr, size_t size);

// ---------
// $> cat main.c
// void	print_memory(const void *addr, size_t size);

// int	main(void)
// {
// 	int	tab[10] = {0, 23, 150, 255,
// 	              12, 16,  21, 42};

// 	print_memory(tab, sizeof(tab));
// 	return (0);
// }
// $> gcc -Wall -Wall -Werror main.c print_memory.c && ./a.out | cat -e
// 0000 0000 1700 0000 9600 0000 ff00 0000 ................$
// 0c00 0000 1000 0000 1500 0000 2a00 0000 ............*...$
// 0000 0000 0000 0000                     ........$

void convertByteToHex(unsigned char byte)
{
	unsigned char first4bit = byte / 16;
	first4bit += (first4bit >= 0 && first4bit <= 9) ? '0' : 'a' - 10;
	write(1, &first4bit, 1); 



	unsigned char next4bit = byte % 16;
	next4bit += (next4bit >= 0 && next4bit <= 9) ? '0' : 'a' - 10;
	write(1, &next4bit, 1);

} 

int printASCIIorDot(unsigned char c)
{
	return (c >= 32 && c <= 126) ? c : 46;
}
void print16ascii(unsigned char *start)
{
	int i = 0;

		while (i < 16)
		{
			unsigned char tmp = printASCIIorDot(*start);
			write(1, &tmp, 1);
			start++;
			i++;
		}
		write(1, "\n", 1); 
	
}

void	print_memory(const void *addr, size_t size)
//void printbytes(unsigned char * tab, size_t size)
{
	//unsigned char * start2 = start;
	
	int i;
	
	if (!size || !addr)
		return ;

	int rows = size / 16;
	int rest = size % 16;
	unsigned char * tmp = (unsigned char*) addr;
	unsigned char * tmp2 = (unsigned char*) addr;



			
// printing main part

		while (rows--)
		{
			i = 0;
			
			while (i < 16)
			{
				
				convertByteToHex(*tmp);
				if (i % 2 && i != 2)
					write(1, " ", 1);
				i++;
				tmp++;
		
			}
			print16ascii(tmp2);

			tmp2 += 16;
		}

//printing rest 
		i = 0;

		while (i < rest)
			{
				
				convertByteToHex(*tmp);
				if (i % 2 && i != 2)
					write(1, " ", 1);
				i++;
				tmp++;
		
			}
		while (i < 16)
		{
			write(1, "  ", 2);
			if (i % 2 && i != 2)
					write(1, " ", 1);
			i++;
		}


		i = 0;

		while (i < rest)
		{
			unsigned char tmp3 = printASCIIorDot(*tmp2);
			write(1, &tmp3, 1);
			tmp2++;
			i++;
		}
		write(1, "\n", 1); 

}

int main (int ac, char ** av)
{
	av = 0;
	// unsigned char s [] = "abcd";
	//int	tab[30] = {65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90};
	//char str [20] = "1234567890";
	char str [1024] = "as it is known since. This code\narises from reorder and expand the set of symbols and characters already used in telegraphy at that time by the Bell company.At first only included capital letters and numbers , but in 1967 was added the lowercase letters and some control characters, forming what is known as US-ASCII, ie the characters 0 through 127.So with this set of only 128 characters was published in 1967 as standard, containing all you need to write in English language.In 1981, IBM developed an extension of 8-bit ASCII code, called";

	//char str [1] = "";

	if (ac == 1)
	{

		size_t size = 61;
		// int rows = size / 16;
		// // int rest = size % 16;
		 
		// while (rows--)
		// {
		// 	print16bytes(tmp);
		// 	print16ascii(tmp);
		// 	tmp += 16;
		// }
		
		print_memory((const void *)str, size);

		//print16ascii((unsigned char *) tab);


	}
	return 0;
}
