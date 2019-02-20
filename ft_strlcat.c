#include "libft.h"

char	*ft_strncat(char *d, const char *s, size_t n)
{
	unsigned int i;
	int j;

	i = 0;
	j = ft_strlen(d);

	while (s[i] != '\0' && i < n)
	{
		d[j] = s[i];
		i++;
		j++;
	}
	d[j] = '\0';
	return (d);
	}

