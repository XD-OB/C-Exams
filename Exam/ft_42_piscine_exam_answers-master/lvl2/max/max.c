/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frodrigu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 02:50:24 by frodrigu          #+#    #+#             */
/*   Updated: 2018/02/01 03:48:00 by frodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	max(int* tab, unsigned int len)
{
	int i;
	int ans;

	i = 0;
	ans = 0;
	if (tab[0] == '\0')
		return (0);
	while (i < len)
	{
		if (tab[i] > ans)
			ans = tab[i];
		i++;
	}
	return (ans);
}
