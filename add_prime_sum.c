#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>

int isPrime(int n)
{
	if (n == 0 || n < 0 || n == 1)
		return 0;
	
	int i = 2;
	
	while (i < n)
	{	
		if (n % i == 0)
			return 0;
		else 
			i++;
	}
	return 1;
}

int addSum(int n)
{
	long r = 0;
	int i  = 2;

	while (i <= n)
	{
		r += (isPrime(i) ? i : 0);
		i++;
	}
	return (int)r;

}

int myatoi (char * s)
{
	long r = 0;

	while (*s == 32 || (*s <= 13 && *s >= 9))
		s++;

	int sign = 1;
	sign = (*s == '-')	? -1 : 1;

	(*s == '-' || *s == '+') ? s++ : s;

	
	while (*s && (*s >= 48 && *s <= 57))
	{
		r = r * 10 + *s - '0';
		s++;
	}
	return (int) r * sign;

}

void putn(int n)
{
	char c;

	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		write(1, "\n", 1);
		exit(1);
	}		

	else if (n < 0)
	{
		write(1, "-", 1);
		putn(-n);
	}

	else if (n ==  0)
	{
		write(1, "0", 1);
		exit(1);
	}


	if (n < 10 && n >= 0) 
	{
		c = n + '0';
		write(1, &c, 1);
	}
	else 
	{
		putn(n/10);
		c = n % 10 + '0';
		write(1, &c, 1);
	}

}

int main(int ac, char ** av)
{
	if (ac != 2)
	{
		write(1, "\n", 1);
		return 0;
	}
	
	if (myatoi(av[1]) <= 0)
	{
		write(1, "0", 1);
		write(1, "\n", 1);
		return 0;
	}

	putn(addSum(myatoi(av[1])));
	write(1, "\n", 1);
//	printf("%d\n", myatoi(av[1]));
	return 0;

}
