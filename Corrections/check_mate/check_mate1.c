/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_mate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishaimou <ishaimou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 19:58:20 by ishaimou          #+#    #+#             */
/*   Updated: 2019/02/26 20:16:01 by ishaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

int	is_ennemy(char c)
{
	if (c == 'Q' || c == 'B' || c == 'P' || c == 'R')
		return (1);
	return (0);
}

int	check_mate_p(int x, int y, int size, char **map)
{
	if (y == size - 1)
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
	int		i = x;

	while (++i < size && map[y][i] != 'P' && map[y][i] != 'B')
		if (map[y][i] == 'R' || map[y][i] == 'Q')
			return (1);
	i = x;
	while (--i >= 0 && map[y][i] != 'P' && map[y][i] != 'B')
		if (map[y][i] == 'R' || map[y][i] == 'Q')
			return (1);
	i = y;
	while (++i < size && map[i][x] != 'P' && map[i][x] != 'B')
		if (map[i][x] == 'R' || map[i][x] == 'Q')
			return (1);
	i = y;
	while (--i >= 0 && map[i][x] != 'P' && map[i][x] != 'B')
		if (map[i][x] == 'R' || map[i][x] == 'Q')
			return (1);
	return (0);
}

int	check_mate_bq(int x, int y, int size, char **map)
{
	int		i = y;
	int		j = x;

	while (++i < size && ++j < size && map[i][j] != 'P' && map[i][j] != 'R')
		if (map[i][j] == 'B' || map[i][j] == 'Q')
			return (1);
	i = y;
	j = x;
	while (++i < size && --j >= 0 && map[i][j] != 'P' && map[i][j] != 'R')
		if (map[i][j] == 'B' || map[i][j] == 'Q')
			return (1);
	i = y;
	j = x;
	while (--i >= 0 && ++j < size && map[i][j] != 'P' && map[i][j] != 'R')
		if (map[i][j] == 'B' || map[i][j] == 'Q')
			return (1);
	i = y;
	j = x;
	while (--i >= 0 && --j >= 0 && map[i][j] != 'P' && map[i][j] != 'R')
		if (map[i][j] == 'B' || map[i][j] == 'Q')
			return (1);
	return (0);
}

int	check_mate(int x, int y, int size, char **map)
{
	return (check_mate_p(x, y, size, map)
			|| check_mate_rq(x, y, size, map)
			|| check_mate_bq(x, y, size, map));
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
	write(1, "\n", 1);
	return (0);
}
