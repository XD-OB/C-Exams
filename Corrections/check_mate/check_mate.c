/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 22:07:08 by obelouch          #+#    #+#             */
/*   Updated: 2019/06/15 17:54:38 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		is_oneof(char x, char* s)
{
	if (x == s[0] || x == s[1])
		return (1);
	return (0);
}

int		p(char **tab, int size, int ky, int kx)
{
	if (ky == size - 1)
		return (0);
	if (kx > 0 && tab[ky + 1][kx - 1] == 'P')
		return (1);
	if (kx < size - 1 && tab[ky + 1][kx + 1] == 'P')
		return (1);
	return (0);
}

int		rq(char **tab, int size, int ky, int kx)
{
	int		i;

	i = kx;
	while (++i < size && !is_oneof(tab[ky][i], "PB"))
		if (is_oneof(tab[ky][i], "RQ"))
			return (1);
	i = kx;
	while (--i >= 0 && !is_oneof(tab[ky][i], "PB"))
		if (is_oneof(tab[ky][i], "RQ"))
			return (1);
	i = ky;
	while (++i < size && !is_oneof(tab[i][kx], "PB"))
		if (is_oneof(tab[i][kx], "RQ"))
			return (1);
	i = ky;
	while (--i >= 0 && !is_oneof(tab[i][kx], "PB"))
		if (is_oneof(tab[i][kx], "RQ"))
			return (1);
	return (0);
}

int		bq(char **tab, int size, int ky, int kx)
{
	int		i;
	int		j;

	i = ky;
	j = kx;
	while (++i < size && ++j < size && !is_oneof(tab[i][j], "PR"))
		if (is_oneof(tab[i][j], "BQ"))
			return (1);
	i = ky;
	j = kx;
	while (++i < size && --j >= 0 && !is_oneof(tab[i][j], "PR"))
		if (is_oneof(tab[i][j], "BQ"))
			return (1);
	i = ky;
	j = kx;
	while (--i >= 0 && ++j < size && !is_oneof(tab[i][j], "PR"))
		if (is_oneof(tab[i][j], "BQ"))
			return (1);
	i = ky;
	j = kx;
	while (--i >= 0 && --j >= 0 && !is_oneof(tab[i][j], "PR"))
		if (is_oneof(tab[i][j], "BQ"))
			return (1);
	return (0);
}

int		check_mate(char **tab, int size, int ky, int kx)
{
	return (p(tab, size, ky, kx) ||
			bq(tab, size, ky, kx) ||
			rq(tab, size, ky, kx));
}

int		main(int ac, char **av)
{
	int		ky, kx;
	int		i, j;

	if (ac > 1)
	{
		av++;
		ac--;
		i = -1;
		while (++i < ac)
		{
			j = -1;
			while (av[i][++j])
				if (av[i][j] == 'K')
				{
					ky = i;
					kx = j;
				}
		}
		if (check_mate(av, ac, ky, kx))
			write(1, "Success\n", 8);
		else
			write(1, "Fail\n", 5);
	}
	else
		write(1, "\n", 1);
	return (0);
}
