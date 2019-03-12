/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frodrigu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 08:58:49 by frodrigu          #+#    #+#             */
/*   Updated: 2018/02/01 09:15:22 by frodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_hex(unsigned int n)
{
	if (n >= 16)
		print_hex(n / 16);
	if (n % 16 < 10)
		ft_putchar((n % 16) + 48);
	else
		ft_putchar((n % 16) - 10 + 97);
}

int		ft_printhex_atoi(char *str)
{
	int i;
	int res;

	i = 0;
	res = 0;
	while (str[i] && str[i] <= 32)
		i++;
	if (str[i] == '-')
		return (-1);
	if (str[i] == '+')
		i++;
	while (str[i])
	{
		if (str[i] < '0' && str[i] > '9')
			return (-1);
		res = res * 10 + (str[i] - 48);
		i++;
	}
	return (res);
}

int		main(int argc, char **argv)
{
	int	n;

	if (argc == 2)
	{
		if ((n = ft_printhex_atoi(argv[1])) != -1)
			print_hex(n);
	}
	ft_putchar('\n');
	return (0);
}
