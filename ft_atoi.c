# include <unistd.h>
# include <stdio.h>

# include <stdlib.h>

int isSpace (char c)
{
	return ((c == 32 || (c >= 9 && c <= 13))?1:0);
}

int	ft_atoi(const char *str)
{
	int sign;

	long r;
	
	while (isSpace(*str))
		str++;
	sign =( (*str == '-')?-1:1);

	(*str == '-' || *str == '+' )? str++: str;

	r = 0;
	while (*str >= '0' && *str <= '9')
		r = r * 10 + *str++ - '0';
	return ((int)r *sign);
}

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void ft_putstr (char *s)
{
	while (*s)
		write(1, s++, 1);
}
void	ft_putnbr(int n)
{
	if (n == -2147483648)
		ft_putstr("-2147483648");
	else if (n < 0)
	{		
		ft_putchar('-');
		ft_putnbr(-n);
	}
	else if (n >= 10)
	{
		ft_putnbr(n/10);
		ft_putchar(n%10 + '0');
	}
	else 
		ft_putchar (n + '0');
}

int isPrime(int n)
{
	int i;
	i = 2;
	if (n <= 0 || n == 1)
		return 0;
	else
	{
		while (i < n)
		{
			if (n % i == 0)
				return 0;
			else 
				i++;
		}
		return 1;
	}	
}

int addPrimeSum (int n)
{
	int i = 0;
	long res = 0;
	while (i <= n)
	{
		res += (isPrime(i)? i: 0);
		i++;
	}

		
		return (int)res;
}

void fprime (int n)
{
	int flag = 0;
	int i = 2;
	while (n > 1)
		if (n % i == 0)
		{	if (flag != 0)
				printf("*");
			printf("%d", i);
			flag = 1;
			n /= i;
		}

		else 
			i++;
}


int main (int ac, char ** av)
{
	if (ac == 2)
	{
	//ft_putnbr( addPrimeSum(ft_atoi(av[1])));
	fprime(ft_atoi(av[1]));
	}
	return 0;
}


