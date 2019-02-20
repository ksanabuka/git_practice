# include <stdio.h>
# include <string.h>


size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		i;
	int			j;
	size_t		dst_len;
	size_t		src_len;

	i = strlen(dst);
	j = 0;
	dst_len = strlen(dst);
	src_len = strlen(src);
	if (size < dst_len + 1)
		return (src_len + size);
	if (size > dst_len + 1)
	{
		while (i < size - 1)
			*(dst + i++) = *(src + j++);
		*(dst + i) = '\0';
	}
	return (dst_len + src_len);
}

int main()
{
    char d[10] = "abcd";
	char * s = "xyk";
	unsigned int n = 9;
	
	printf("%zu \n", strlcat(d, s, n));
	printf("%zu \n", ft_strlcat(d, s, n));
}

