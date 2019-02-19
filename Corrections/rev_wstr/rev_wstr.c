#include <unistd.h>
#include <stdio.h> //!!!!!!!!!!!!!!!

int		is_blank(char c)
{
	return (c == 32 || c == 9);
}

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

void	rev_wstr(char *str)
{
	int		wc = 0;
	int		i = 0;

	while (str[i++])
		if (is_blank(str[i]))
			wc++;
	while (*str)
		str++;
	str--;
	while (wc + 1)
	{
		while (!is_blank(*str) && *str)
			str--;
		*str = '\0';
		ft_putstr(str + 1);
		if (wc)
			ft_putstr(" ");
		str--;
		wc--;
	}
}

int		main(int argc, char *argv[])
{
	if (argc == 2)
		rev_wstr(argv[1]);
	write(1, "\n", 1);
	return (0);
}
