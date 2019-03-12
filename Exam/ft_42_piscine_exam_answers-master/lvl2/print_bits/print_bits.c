/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frodrigu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 05:56:07 by frodrigu          #+#    #+#             */
/*   Updated: 2018/02/01 06:21:22 by frodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_bits(unsigned char octet)
{
	int		div;
	char	num;

	div = 128;
	num = octet;
	while (div > 0)
	{
		if (div > num)
			ft_putchar('0');
		else
		{
			ft_putchar('1');
			num %= div;
		}
		div /= 2;
	}
}

