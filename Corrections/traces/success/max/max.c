/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishaimou <ishaimou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 09:54:33 by ishaimou          #+#    #+#             */
/*   Updated: 2019/02/04 09:55:30 by ishaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		max(int* tab, unsigned int len)
{
	int				max;

	max = 0;
	if (len)
	{
		max = tab[--len];
		while (len--)
			if (tab[len] > max)
				max = tab[len];
	}
	return (max);
}
