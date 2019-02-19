/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrange.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishaimou <ishaimou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 08:17:06 by ishaimou          #+#    #+#             */
/*   Updated: 2019/02/05 08:17:38 by ishaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_rrange(int start, int end)
{
	int		*tab;
	int		i;
	int		size;
	int		step;

	size = (start < end) ? (end - start + 1) : (start - end + 1);
	step = (start < end ) ? -1 : 1;
	tab = (int*)malloc(sizeof(int) * size);
	i = size;
	while (--i >= 0)
		tab[i] = end + i * step;
	return (tab);
}
