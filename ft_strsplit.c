#include<stdlib.h>
#include <string.h>


void	*ft_memset(void *b, int c, size_t len)
{
	while (len > 0)
	{
		len--;
		((unsigned char *)b)[len] = (unsigned char)c;
	}
	return (b);
}
void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}


void	*ft_memalloc(size_t size)
{
	void *ptr;

	ptr = malloc(size);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, size);
	return (ptr);
}
char	*ft_strnew(size_t size)
{
	return (ft_memalloc((size + 1) * sizeof(char)));
}

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	i;

	i = 0;
	new = ft_strnew(len);
	if (new == NULL)
		return (NULL);
	while (i < len)
	{
		new[i] = s[start + i];
		i++;
	}
	return (new);
}

int wlen(char * s)
{
	int len = 0;
	int i = 0;
	while (s[i] && s[i] == ' ')
			i++;
	while (s[i] && s[i] != ' ')
	{
		i++;
		len++;
	}
	return len;
}

int wC(char *s, char d)
{
	int i = 0;
	int wc = 0;

	while (s[i])
	{
		while(s[i] == d && s[i])
			i++;
		if (s[i] != '\0')
			wc++;
		while(s[i] != d && s[i])
			i++;
	}	
	return wc;
}

static void cleanup(char **split, int cur)
  {
  	while (cur > 0)
	{
		cur --;
		ft_strdel(&split[cur]);
	}

	ft_strdel(split);
  }	

char			**ft_strsplit(char const *s, char c)
{
	char *s1 = (char *) s;
	char **res;
	int wc = 0;
	wc = wC((char *)s1, ' ');

	if (!(res = (char **)ft_memalloc(sizeof(char *) * (wc + 1))))
		return (NULL);
	int i = 0;
	int cnt = 0;
	char * sub;


	while (cnt < wc)
	{
		while (s1[i] && s1[i] == c)
		{
			i++;
		}

		if  (s1[i])
		{
					
			if (!(sub = (char *)malloc(sizeof(char) * (wlen(&s1[i]) + 1))))
			{
				ft_cleanup(res, cnt);
				return 0;
			}
			sub[wlen(&s1[i])] =  '\0';
			sub = ft_strsub(&s1[i], 0, wlen(&s1[i]));
			res[cnt] = sub;
			cnt++;
		}

		while (s1[i] && s1[i] != c)
		{
			i++;
		}
	}

	res [wc] = NULL;
	
	return (res);

}

#include<stdio.h>

int main (int ac, char ** av)
{
	if (ac == 2)
	{
		char **r = ft_strsplit(av[1], ' ');
		while (**r!= '\0')
	{	
		printf("%s\n", *r);
		r++;
	}
	
}
return 0;
}



