# include<unistd.h>

int  repeat(char c)
{
	int repeat; 
	if (c >= 'A'  && c <= 'Z')
		repeat = c - 'A' + 1;
	else if (c >= 'a'  && c <= 'z')
		repeat = c - 'a' + 1;
	else 
		repeat = 1;

	return repeat;
}

int main (int ac, char ** av)
{
	ac = 0;
	int i;
	i = 0;
	while (*av[1])
	{
		i = repeat(*av[1]);
		while (i != 0)
		{
			write(1, av[1], 1);
			i--;
		}
		av[1]++;
	}

return 0;
}





