/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 22:07:08 by obelouch          #+#    #+#             */
/*   Updated: 2019/03/12 22:55:03 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		p(char **av, int ky, int kx, int size)
{
	if (ky == size - 1)
		return (0);
	if (kx > 0 && av[ky + 1][kx - 1] == 'P')
		return (1);
	if (kx < size - 1 && av[ky + 1][kx + 1] == 'P')
		return (1);
	return (0);
}

int		b_q(char **av, int ky, int kx, int size)
{
	int		i = 0;
	int		j = 0;

	while ((ky + --i) >= 0 && (kx + --j) >= 0 && av[ky + i][kx + j] != 'R' && av[ky + i][kx + j] != 'P')
		if (av[ky + i][kx + j] == 'B' || av[ky + i][kx + j] == 'Q')
			return (1);
	j = i = 0;
	while ((ky + ++i) < size && (kx + ++j) < size && av[ky + i][kx + j] != 'R' && av[ky + i][kx + j] != 'P')
		if (av[ky + i][kx + j] == 'B' || av[ky + i][kx + j] == 'Q')
			return (1);
	j = i = 0;
	while ((ky + ++i) < size && (kx + --j) >= 0 && av[ky + i][kx + j] != 'R' && av[ky + i][kx + j] != 'P')
		if (av[ky + i][kx + j] == 'B' || av[ky + i][kx + j] == 'Q')
			return (1);
	j = i = 0;
	while ((ky + --i) >= 0 && (kx + ++j) < size && av[ky + i][kx + j] != 'R' && av[ky + i][kx + j] != 'P')
		if (av[ky + i][kx + j] == 'B' || av[ky + i][kx + j] == 'Q')
			return (1);
	return (0);
}

int		r_q(char **av, int ky, int kx, int size)
{
	int		i = kx;

	while (++i < size && av[ky][i] != 'B' && av[ky][i] != 'P')
		if (av[ky][i] == 'R' || av[ky][i] == 'Q')
			return (1);
	i = kx;
	while (--i >= 0 && av[ky][i] != 'B' && av[ky][i] != 'P')
		if (av[ky][i] == 'R' || av[ky][i] == 'Q')
			return (1);
	i = ky;
	while (++i < size && av[i][kx] != 'B' && av[i][ky] != 'P')
		if (av[i][kx] == 'R' || av[i][kx] == 'Q')
			return (1);
	i = ky;
	while (--i >= 0 && av[i][kx] != 'B' && av[i][kx] != 'P')
		if (av[i][kx] == 'R' || av[i][kx] == 'Q')
			return (1);
	return (0);
}

int		checkmate(char	**av)
{
	int			kx;
	int			ky;
	int			size = 0;
	int			i = -1;
	int			j;

	while (av[0][size])
		size++;
	while (++i < size)
	{
		j = -1;
		while (++j < size)
		{
			if (av[i][j] == 'K')
			{
				kx = j;
				ky = i;
			}
		}
	}
	return (r_q(av, ky, kx, size) || b_q(av, ky, kx, size) || p(av, ky, kx, size));
}

int		main(int ac, char **av)
{
	if (ac != 1)
	{
		av++;
		if (checkmate(av))
			write(1, "Success", 7);
		else
			write(1, "Fail", 4);
	}
	write(1, "\n", 1);
}
