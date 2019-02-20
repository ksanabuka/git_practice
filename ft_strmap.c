char * ft_strmap(char const *s, char (*f)(char))
{
	char * res;

	res = (char *)res *sizeof(char) * (ft_strlen(s)+1);

	if (!res)
		return (NULL);
	unsigned int i = 0;
	
	while (s[i])
	{
		res[i] = f(s[i]);
		i++;
	}
	res[i] = '\0';

	return (res);
}
