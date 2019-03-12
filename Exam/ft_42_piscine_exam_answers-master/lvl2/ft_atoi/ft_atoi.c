/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frodrigu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 03:27:05 by frodrigu          #+#    #+#             */
/*   Updated: 2018/01/31 03:33:10 by frodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

int	ft_atoi(const char *str)
{
	int		i;
	bool	neg;
	int		res;

	i = 0;
	neg = false;
	res = 0;
	while (str[i] <= 32)
		i++;
	if (str[i] == '-')
		neg = true;
	while (str[i] == '-' || str[i] == '+')
		i++;
	while ((str[i] >= '0' && str[i] <= '9') && str[i] != '\0')
	{
		res *= 10;
		res += (int)str[i] - '0';
		i++;
	}
	if (neg)
		return (-res);
	else
		return (res);
}
