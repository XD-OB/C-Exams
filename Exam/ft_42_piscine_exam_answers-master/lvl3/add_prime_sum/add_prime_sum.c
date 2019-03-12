/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_prime_sum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frodrigu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 07:52:21 by frodrigu          #+#    #+#             */
/*   Updated: 2018/02/01 08:45:03 by frodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdbool.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_is_prime(int num)
{
	int i;

	i = 2;
	while (i <= (num / 2))
	{
		if (num % i == 0)
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int		ft_atoi(char *str)
{
	int		i;
	int		res;

	i = 0;
	res = 0;
	if (str[i] == '-')
		return (0);
	while (str[i])
	{
		if (!(str[i] >= 48 && str[i] <= 57))
			return (0);
		res *= 10;
		res += (str[i] - 48);
		i++;
	}
	return (res);
}

void	ft_putnbr(int n)
{
	char c;

	if (n >= 10)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
	{
		c = n + '0';
		ft_putchar(c);
	}
}

void	ft_add_prime_sum(int n)
{
	int i;
	int ans;

	i = 2;
	ans = 0;
	while (i <= n)
	{
		if (ft_is_prime(i))
			ans += i;
		i++;
	}
	ft_putnbr(ans);
}

int	main(int argc, char **argv)
{
	int i;
	int	ans;

	i = 0;
	ans = 0;
	if (argc == 2)
		ft_add_prime_sum(ft_atoi(argv[1]));
	else
		ft_putchar('0');
	ft_putchar('\n');
	return (0);
}
