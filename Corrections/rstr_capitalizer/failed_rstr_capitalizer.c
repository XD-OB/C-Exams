#include <unistd.h>

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

int		is_blank(char c)
{
	return (c == 9 || c == 32);
}

int		is_lowercase(char c)
{
	return (c < 123 && c > 96);
}

void	ft_str_tolower(char *str)
{
	int		i;
	
	i = 0;
	while (str[i])
	{
		if (str[i] < 91 && str[i] > 64)
			str[i] += 32;
		i++;
	}
}

int		main(int argc, char *argv[])
{
	int		i;
	int		j;
	int		flag;
	int		last;

	if (argc > 1)
	{
		i = 0;
		flag = 0;
		while (++i < argc)
		{
			ft_str_tolower(argv[i]);
			j = 0;
			while (argv[i][j])
			{
				if (is_lowercase(argv[i][j]))
				{
						flag = 1;
						last = j;
				}
				if ((!argv[i][j + 1] || is_blank(argv[i][j + 1])) && flag)
				{
					argv[i][last] -= 32;
					flag = 0;
				}	
				j++;
			}
			ft_putstr(argv[i]);
			ft_putstr("\n");
		}
	}
	else
		ft_putstr("\n");
	return (0);
}
