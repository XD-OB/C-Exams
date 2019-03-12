/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_mult.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frodrigu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 09:20:06 by frodrigu          #+#    #+#             */
/*   Updated: 2018/02/01 12:18:20 by frodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_atoi_tab_mult(char *str)
{
	int	res;
	int i;

	res = 0;
	i = 0;
	while (str[i])
	{
		res *= 10;
		res	+= (int)str[i] - '0';
		i++;
	}
	return (res);
}

void	ft_putnbr(int nb)
{
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
		ft_putchar(nb + '0');
}

int		main(int argc, char **argv)
{
	int		nb;
	int		mult;
	int		ans;
	int		i;

	nb = 0;
	ans = 0;
	mult = 1;
	i = 0;
	if (argc != 2)
	{
		ft_putchar('\n');
		return (0);
	}
	nb = ft_atoi_tab_mult(argv[1]);
	while (mult <= 9 && nb <= 23860924)
	{
		ft_putnbr(mult);
		ft_putchar(' ');
		ft_putchar('x');
		ft_putchar(' ');
		while (argv[1][i] != '\0')
		{
			ft_putchar(argv[1][i]);
			i++;
		}
		i = 0;
		ft_putchar(' ');
		ft_putchar('=');
		ft_putchar(' ');
		ans = mult * nb;
		ft_putnbr(ans);
		ft_putchar('\n');
		mult++;
	}
	return (0);
}
