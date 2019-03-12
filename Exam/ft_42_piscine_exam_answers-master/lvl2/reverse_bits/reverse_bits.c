/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_bits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frodrigu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 02:20:03 by frodrigu          #+#    #+#             */
/*   Updated: 2018/02/01 02:31:03 by frodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned char	reverse_bits(unsigned char octet)
{
	unsigned char	result;

	result = octet;
	while (octet)
	{
		result <<= 1;
		result |= octet & 1;
		octet >>= 1;
	}
	result <<= 1;
	return (result);
}
