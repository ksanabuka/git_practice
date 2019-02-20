char *   strchr(const char *s, int c)
{
		while (*s && *s != c)
			s++;
		if (c == '\0')
		{
			return s;
		}
		if (*s == '\0')
			return (NULL);
		if (*s == c)
			return c;

}

char * strrchr(const char *s, int c)
{
	int i = 0;

	while (s[i])
	{
		i++;
	}

	while (i >= 0)
	{
		if (s[i] == (char)c)
			return (&s[i])
		else 
			i--;	
	}
	return (NULL);
}
