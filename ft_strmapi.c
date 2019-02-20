char * ft_strmapi(char * s, (char)(*f)(int, char))
{
	char * res;

	res = ft_strnew(ft_strlen(s) + 1);

	if (!res)
		return (NULL);

	int i = 0;
	while (s[i])
	{
		res[i] = f(i, s[i]);
		i++;
	}
	
	res[i] = '\0';

	return (res);
}


