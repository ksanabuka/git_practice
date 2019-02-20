char *ft_strcpy(char *s1, char *s2)
{
	while (*s2)
	{
		*s1 = *s2;
		s1++;
		s2++;
	}
	*s1 = *s2;
	return s1;
}
int ft_strlen(char *s)
{
	int i = 0;
	while (*s)
	{
		s++;
		i++;
	}
	return i;
}

#include<stdio.h>
int main (void)
{
 char s1[] = "Flavio";
 //char s2[] = "Gaucho";

 printf("%d \n", ft_strlen(s1));
ft_strlen(s1);
// printf("%s \n", s1);
}
