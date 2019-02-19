#include <unistd.h>

int		is_blank(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\r'
			|| c == '\f' || c == '\v');
}

int		is_num(char c)
{
	return (c >= '0' && c <= '9');
}


void		ft_putchar(char c)
{
	write(1, &c, 1);
}

void		ft_putstr(char *s)
{
	while (*s)
		write(1, s++, 1);
}

void	ft_putnbr(int nb)
{
	if (nb < 0)
	{
		ft_putchar('-');
		if (nb == -2147483648)
		{
			ft_putchar('2');
			ft_putnbr(147483648);
			return;
		}
		else
			nb = -nb;
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
		ft_putchar(nb + 48);
}

int		ft_atoi(char *str)
{
	int		is_signed;
	int		ret;

	is_signed = 0;
	ret = 0;
	while (is_blank(*str))
		str++;
	if (*str == '-')
		is_signed = 1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str && is_num(*str))
	{
		ret = (ret * 10) + (*str - 48);
		str++;
	}
	if (is_signed == 1)
		return (-ret);
	return (ret);
}

int	main(int argc, char **argv)
{
	int		i;

	i = 0;
	if (argc == 2)
	{
		while (++i < 10)
		{
			ft_putnbr(i);
			ft_putstr(" x ");
			ft_putstr(argv[1]);
			ft_putstr(" = ");
			ft_putnbr(i * ft_atoi(argv[1]));
			ft_putchar('\n');
		}
	}
	else
		ft_putchar('\n');
	return (0);
}
