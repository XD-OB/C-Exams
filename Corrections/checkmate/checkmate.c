#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i = 0;

	while (str[i])
		i++;
	return (i);
}

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

int	check_square(int size, char **map)
{
	int	i = -1;

	while (++i < size)
		if (ft_strlen(map[i]) != size)
			return (0);
	return (1);
}

int	is_ennemy(char c)
{
	if (c == 'Q' || c == 'B' || c == 'P' || c == 'R')
		return (1);
	return (0);
}

int	check_mate_p(int x, int y, int size, char **map)
{
	if (y == size)
		return (0);
	if (x != size - 1)
	{
		if (map[y + 1][x + 1] == 'P')
			return (1);
	}
	if (x != 0)
	{
		if (map[y + 1][x - 1] == 'P')
			return (1);
	}
	return (0);
}

int	check_mate_rq(int x, int y, int size, char **map)
{
	int		i = -1;

	while (++i < size)
		if (map[i][x] == 'R' || map[i][x] == 'Q' || map[y][i] == 'R' || map[y][i] == 'Q')
			return (1);
	return (0);
}

int	check_mate_bq(int x, int y, int size, char **map)
{
	int		i = -1;
	int		j;

	while (++i < size)
	{
		j = -1;
		while (++j < size)
		{
			if (x + j == y + i && (map[i][j] == 'B' || map[i][j] == 'Q'))
					return (1);
		}
	}
	return (0);	
}

int	check_mate(int x, int y, int size, char **map)
{
	return (check_mate_p(x, y, size, map)
		|| check_mate_rq(x, y, size, map)
		|| check_mate_bq(x, y, size, map));
}

void	print_map(char **map)
{
	while (*map)
	{
		ft_putstr("\t");
		ft_putstr(*map);
		ft_putstr("\n");
		map++;
	}
}

int	main(int ac, char **av)
{
	int	kx = -1;
	int	ky = -1;
	int	i = -1;
	int	ennemy = 0;
	int	j;

	if (ac > 1)
	{
		av++;
			print_map(av);
		if (check_square(ac - 1, av))
		{
			while (++i < ac - 1)
			{
				j = -1;
				while (++j < ac - 1)
				{
					if (av[i][j] == 'K')
					{
						kx = j;
					  	ky = i;
					}
					if (is_ennemy(av[i][j]))
						ennemy++;
				}
			}
			if (!ennemy)
				write(1, "Fail", 4);
			else if (check_mate(kx, ky, ac - 1, av))
				write(1, "Success", 7);
			else
				write(1, "Fail", 4);
		}
	}	
	write(1, "\n", 1);
	return (0);
}
