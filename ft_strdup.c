#include <stdlib.h>
#include <stdio.h>
int len(char *s)
{
	int i = 0;
	while(s[i] != '\0')
	{
		i++;
	}
return i;
}

char *ft_strdup(char *src)
{
	char * r;
	r  = (char *)malloc (sizeof(*r) * (len(src) + 1));
	if (!r)
		return 0;
	int i = 0;
	int len;
   len 	= len(src) + 1;


   while (i <= len)
   {
   	r[i] = src[i];
	
	i++;
   }	   
	r[len] = '\0';

	return r;
}

int main (void)

{
	printf("%s \n", ft_strdup("Salut"));
	return 0;
}
