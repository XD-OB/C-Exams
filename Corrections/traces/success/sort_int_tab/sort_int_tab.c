/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_int_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishaimou <ishaimou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/03 10:55:45 by ishaimou          #+#    #+#             */
/*   Updated: 2019/02/03 10:56:28 by ishaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void sort_int_tab(int *tab, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	int				count;
	int				tmp;

	i = -1;
	count = 1;
	while (count && ++i < size - 1)
	{
		count = 0;
		j = -1;
		while (++j < size - 1)
		{
			if (tab[j + 1] < tab[j])
			{
				count++;
				tmp = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = tmp;
			}
		}
	}
}
