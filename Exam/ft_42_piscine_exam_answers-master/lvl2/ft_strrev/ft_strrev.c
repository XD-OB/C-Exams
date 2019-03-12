/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frodrigu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 06:53:45 by frodrigu          #+#    #+#             */
/*   Updated: 2018/02/01 07:32:26 by frodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

char *ft_strrev(char *str)
{
	int		i;
	int		j;
	char	tmp;

	i = 0;
	j = 0;
	while (str[i] != '\0')
		i++;
	while (i > j)
	{
		tmp = str[j];
		str[j] = str[i - 1];
		str[i - 1] = tmp;
		j++;
		i--;
	}
	return (str);
}

int	main(void)
{
	char a[] = "1234567890";

	printf("%s", ft_strrev(a));
	return (0);
}
