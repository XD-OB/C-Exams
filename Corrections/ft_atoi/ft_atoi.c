/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishaimou <ilyass.sh@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 21:24:59 by ishaimou          #+#    #+#             */
/*   Updated: 2018/12/26 21:42:49 by ishaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		is_blank(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '\f' || c == '\v');
}

int		is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

int		ft_atoi(const char *str)
{
	int		is_signed;
	int		ret;

	ret = 0;
	is_signed = 0;
	while (is_blank(*str))
		str++;
	if (*str == '-')
		is_signed = 1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str && is_digit(*str))
	{
		ret = (ret * 10) + (*str - 48);
		str++;
	}
	return (is_signed ? -ret : ret);
}
