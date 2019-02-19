#include <stdlib.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nbr)
{
	if (nbr < 0)
	{
		ft_putchar('-');
		if (nbr == -2147483648)
		{
			ft_putchar('2');
			ft_putnbr(147483648);
			return ;
		}
		else
			nbr *= -1;
	}
	if (nbr > 9)
	{
		ft_putnbr(nbr / 10);
		ft_putnbr(nbr % 10);
	}
	else
		ft_putchar(nbr + 48);
}

int		ft_atoi(char *str)
{
	int		sign;
	int		result = 0;

	while (*str && (*str == 32 || (*str >= 9 && *str <= 13)))
		str++;
	sign = (*str == '-') ? -1 : 1;
	(*str == '-' || *str == '+') ? str++ : 0;
	while (*str && *str <= 57 && *str >= 48)
	{
		result = (result * 10) + (*str - 48);
		str++;
	}
	return (result * sign);
}

int		is_prime (unsigned int nbr)
{
	unsigned int	i = 1;
	
	while (++i < nbr)
		if (nbr % i == 0)
			return (0);
	return (1);
}

void	add_prime_sum(unsigned int nbr)
{
	int				sum = 0;
	unsigned int	i = 1;

	while (++i <= nbr)
		if (is_prime(i))
			sum += i;
	ft_putnbr(sum);
	ft_putchar('\n');
}

int		main(int argc, char *argv[])
{
	if (argc == 2 && ft_atoi(argv[1]) >= 0)
		add_prime_sum(ft_atoi(argv[1]));
	else
		write(1, "0\n", 2);
	return (0);
}
