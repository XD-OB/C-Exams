/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishaimou <ishaimou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 11:37:16 by ishaimou          #+#    #+#             */
/*   Updated: 2019/02/08 10:17:15 by ishaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_itoa_base(int value, int base)
{
	long	nb;
	int		size;
	int		sign;
	char	*result;

	sign = (value < 0 && base == 10) ? 1 : 0;
	size = sign ? 2 : 1;
	nb = (value < 0) ? -(long)value : value;
	while (nb /= base)
		size++;
	result = (char*)malloc(sizeof(char) * (size + 1));
	result[size] = '\0';
	nb = (value < 0) ? -(long)value : value;
	if (sign)
		result[0] = '-';
	while (size-- > sign)
	{
		result[size] = (nb % base < 10) ? (nb % base + '0') : (nb % base - 10 + 'A');
		nb /= base;
	}
	return (result);
}
