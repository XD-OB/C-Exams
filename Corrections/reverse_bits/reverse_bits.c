/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_bits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishaimou <ishaimou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 02:23:34 by ishaimou          #+#    #+#             */
/*   Updated: 2019/01/27 02:23:37 by ishaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned char	reverse_bits(unsigned char octet)
{
	unsigned char	ret = 0;
	unsigned char	len = 8;

	while (len--)
	{
		ret = (ret << 1) | (octet & 1);
		octet >>= 1;
	}
	return (ret);
}
