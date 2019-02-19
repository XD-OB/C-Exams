/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishaimou <ishaimou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 03:04:01 by ishaimou          #+#    #+#             */
/*   Updated: 2019/01/29 03:09:17 by ishaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_point.h"

t_point ft_point(int x, int y)
{
	t_point p;

	p.x = x;
	p.y = y;

	return (p);
}

void  flood_fill(char **tab, t_point size, t_point begin)
{
	char	b;

	b = tab[begin.y][begin.x];
	tab[begin.y][begin.x] = 'F';
	if (begin.y + 1 < size.y && tab[begin.y + 1][begin.x] == b)
		flood_fill(tab, size, ft_point(begin.x, begin.y + 1));
	if (begin.y - 1 >= 0 && tab[begin.y - 1][begin.x] == b)
		flood_fill(tab, size, ft_point(begin.x, begin.y - 1));
	if (begin.x + 1 < size.x && tab[begin.y][begin.x + 1] == b)
		flood_fill(tab, size, ft_point(begin.x + 1, begin.y));
	if (begin.x - 1 >= 0 && tab[begin.y][begin.x - 1] == b)
		flood_fill(tab, size, ft_point(begin.x - 1, begin.y));
}
