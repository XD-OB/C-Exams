/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishaimou <ishaimou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 17:17:33 by ishaimou          #+#    #+#             */
/*   Updated: 2019/02/20 17:17:39 by ishaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		is_blank(char c)
{
	return (c == 32 || (c >= 9 && c <= 13));
}

int		ft_atoi(const char *str)
{
	int		result = 0;
	int		sign;

	while(is_blank(*str))
		str++;
	sign = (*str == '-') ? -1 : 1;
	(*str == '-' || *str == '+') ? str++ : 0;
	while (*str && *str >= 48 && *str <= 57)
	{
		result = (result * 10) + (*str - 48);
		str++;
	}
	return (result * sign);
}
