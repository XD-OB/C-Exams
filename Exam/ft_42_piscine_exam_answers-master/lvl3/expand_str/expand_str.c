/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frodrigu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                    		        +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 10:47:56 by frodrigu          #+#    #+#             */
/*   Updated: 2018/02/02 11:20:57 by frodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		check(char *str, int index)
{
	int c;

	c = 0;
	index++;
	while (str[index])
	{
		if (str[index] > 32)
		{
			c = 1;
			break ;
		}
		index++;
	}
	return (c);
}

int		main(int argc, char **argv)
{
	int i;

	i = 0;
	if (argc != 2)
	{
		ft_putchar('\n');
		return (0);
	}
	while (argv[1][i] != '\0')
	{
		while (argv[1][i] <= 32)
			i++;
		while (argv[1][i] > 32)
		{
			ft_putchar(argv[1][i]);
			i++;
		}
		if (argv[1][i] == '\0')
			break ;
		if (check(argv[1], i) == 1)
		{
			if (argv[1][i] <= 32)
			{
				ft_putchar(' ');
				ft_putchar(' ');
				ft_putchar(' ');
			}
		}
		if (check(argv[1], i) == 0)
			break ;
	}
	ft_putchar('\n');
}
