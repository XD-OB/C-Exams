#include <unistd.h>

int		is_blank(char c)
{
	return (c == 32 || c == 9);
}

char	*trim_str(char *str)
{
	int		i = 0;

	if (*str)
	{
		while (is_blank(*str))
			str++;
		while (str[i])
			i++;
		i--;
		while (str[i] && is_blank(str[i]))
			i--;
		str[i + 1] = '\0';
	}
	return (str);
}

void	epur_str(char *str)
{
	str = trim_str(str);
	while (*str)
	{
		if (!is_blank(*str))
		{
			while (*str && !is_blank(*str))
				write(1, str++, 1);	
			if (*str)
				write(1, " ", 1);
		}
		else
			str++;
	}
}

int		main(int argc, char *argv[])
{
	if (argc == 2)
		epur_str(argv[1]);
	write(1, "\n", 1);
	return (0);
}
