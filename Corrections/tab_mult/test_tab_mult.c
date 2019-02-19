#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

void	ft_putnbr(int nb)
{
	if (nb < 0)
	{
		ft_putchar('-');
		if (nb == -2147483648)
		{
			ft_putstr("2147483648");
			return ;
		}
		else
			nb *= -1;
	}
	if (nb > 9)
		ft_putnbr(nb / 10);
	ft_putchar((nb % 10) + 48);
}

int		ft_atoi(char *str)
{
	int		ret = 0;
	int		sign;

	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	sign = (*str == '-') ? -1 : 1;
	(*str == '-' || *str == '-') ? str++ : 0;
	while (*str && *str >= 48 && *str <= 57)
		ret = (ret * 10) + (*str++ - 48);
	return (ret * sign);
}

int		main(int argc, char *argv[])
{
	int		i = 0;
	int		nb;

	if (argc > 1)
	{
		nb = ft_atoi(argv[1]);
		while (++i < 10)
		{
			ft_putnbr(i);
			ft_putstr(" x ");
			ft_putstr(argv[1]);
			ft_putstr(" = ");
			ft_putnbr(nb * i);
			ft_putchar('\n');
		}
	}
	else
		ft_putchar('\n');
	return (0);
}
