/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishaimou <ishaimou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 09:28:05 by ishaimou          #+#    #+#             */
/*   Updated: 2019/02/07 10:20:09 by ishaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_itoa(int nbr)
{
	char	*result;
	long	tmp;
	int		size;
	int		sign;

	sign = (nbr < 0) ? 1 : 0;
	size = sign ? 2 : 1;
	tmp = (nbr < 0) ? -(long)nbr : nbr;
	while (tmp /= 10)
		size++;
	if (!(result = (char*)malloc(sizeof(char) * (size + 1))))
			return (result);
	result[size] = '\0';
	if (sign)
		result[0] = '-';
	tmp = (nbr < 0) ? -(long)nbr : nbr;
	while (--size >= sign)
	{
		result[size] = (tmp % 10) + 48;
		tmp /= 10;
	}
	return (result);
}
