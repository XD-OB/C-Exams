#include <unistd.h>

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

int		main(int argc, char *argv[])
{
	int		i = 0;
	int		j = 0;

	if (argc == 3)
	{
		while (argv[1][i])
		{
			while (argv[2][j] && argv[1][i] != argv[2][j])
				j++;
			if (!argv[2][j])
			{
				ft_putstr("\n");
				return (0);
			}
			i++;
		}
		ft_putstr(argv[1]);
	}
	ft_putstr("\n");
	return (0);
}
