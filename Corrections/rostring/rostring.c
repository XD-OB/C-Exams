/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rostring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 14:38:22 by obelouch          #+#    #+#             */
/*   Updated: 2019/03/12 15:09:20 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char	c)
{
	write(1, &c, 1);
}

int		is_blank(char c)
{
	if ((c >= 9 && c <= 13) || c == ' ')
		return (1);
	return (0);
}

void	rostring(char *str)
{
	int		i = 0;
	int		flag;
	int		posfword;
	int		sizefword;

	while (is_blank(str[i]))
		i++;
	posfword = i;
	while (!is_blank(str[i]))
		i++;
	sizefword = i - posfword;
	while (str[i])
	{
		flag = 0;
		while (str[i] && !is_blank(str[i]))
		{
			ft_putchar(str[i]);
			flag = 1;
			i++;
		}
		while (str[i] && is_blank(str[i]))
			i++;
		if (flag == 1)
			ft_putchar(' ');
	}
	i = -1;
	while (++i < sizefword)
		ft_putchar(str[posfword + i]);
}

int		main(int ac, char **av)
{
	if (ac > 1 && *av[1])
		rostring(av[1]);
	ft_putchar('\n');
	return (0);
}
