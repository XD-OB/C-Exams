/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   biggest_pal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 22:59:11 by obelouch          #+#    #+#             */
/*   Updated: 2019/06/15 22:59:27 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_strlen(char *str)
{
	int		len = 0;

	while (str[len])
		len++;
	return (len);
}

void	bigpal(char *str)
{
	int		high, low;
	int		maxlen, len;
	int		start, i;

	i = 0;
	maxlen = 1;
	len = ft_strlen(str);
	start = len - 1;
	while (++i < len)
	{
		high = low = i;
		while (--low >= 0 && ++high < len && str[low] == str[high])
			if (maxlen <= high - low + 1)
			{
				maxlen = high - low + 1;
				start = low;
			}
		low = i;
		high = i - 1;
		while (--low >= 0 && ++high < len && str[low] == str[high])
			if (maxlen <= high - low + 1)
			{
				maxlen = high - low + 1;
				start = low;
			}
	}
	write(1, &str[start], maxlen);
}

int		main(int ac, char **av)
{
	if (ac == 2)
		bigpal(av[1]);
	write(1, "\n", 1);
	return (0);
}
