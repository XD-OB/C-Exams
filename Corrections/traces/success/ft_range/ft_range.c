/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishaimou <ishaimou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 11:14:25 by ishaimou          #+#    #+#             */
/*   Updated: 2019/02/04 11:16:20 by ishaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int start, int end)
{
	int		*tab;
	int		i;
	int		size;
	int		step;

	size = (start < end) ? (end - start + 1) : (start - end + 1);
	step = (start < end ) ? 1 : -1;
	tab = (int*)malloc(sizeof(int) * size);
	i = -1;
	while (++i < size)
		tab[i] = start + i * step;
	return (tab);
}
