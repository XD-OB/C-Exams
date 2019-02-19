/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishaimou <ishaimou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 04:43:20 by ishaimou          #+#    #+#             */
/*   Updated: 2019/01/29 04:45:25 by ishaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *str)
{
	char	*dup;
	int		i;

	i = 0;	
	dup = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
	while (str[i])
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*ft_itoa(int nbr)
{
	int		i;
	int		count;
	int		size;
	int		tmp;
	char	*tab;
	
	i = 0;
	size = 1;
	if (nbr == -2147483648)
		return (ft_strdup("-2147483648"));
	if (nbr < 0)
		size++;
	tmp = nbr >= 0 ? nbr : -nbr;
	while ((tmp = tmp / 10) > 0)
		size++;
	tab = (char*)malloc(sizeof(char) * (size + 1));
	tab[size] = '\0';
	if (nbr < 0)
	{
		nbr = -nbr;
		tab[i] = '-';
		i++;
	}
	tmp = nbr;
	count = 1;
	while ((tmp = tmp / 10) > 0)
		count *= 10;
	while (i < size && count >= 10)
	{
		tab[i] = (nbr / count) + 48;
		nbr %= count; 
		count /= 10;
		i++;
	}
	tab[i] = (nbr / count) + 48;
	return (tab);
}
