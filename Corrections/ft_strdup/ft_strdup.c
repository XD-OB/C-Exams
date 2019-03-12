#include <stdlib.h>

char    *ft_strdup(char *src)
{
	char	*dup;
	int		len;

	len = 0;
	while (src[len])
		len++;
	if ((dup = (char*)malloc(sizeof(char) * (len + 1))))
	{
		dup[len] = '\0';
		while (--len >= 0)
			dup[len] = src[len];
	}
	return (dup);
}
