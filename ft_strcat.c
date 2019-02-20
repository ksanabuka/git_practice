#include "libft.h"

char	*ft_strcat(char *d, const char *s)
{
	unsigned int i;
	int j;

	i = 0;
	j = ft_strlen(d);

	while (*s++)
	{
		*(d + j) = *(s + i);
		i++;
		j++;
	}
	d[j] = '\0';
	return (d);
}

