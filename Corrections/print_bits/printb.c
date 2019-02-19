#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_bits(unsigned char octet)
{
	int	i = 8;

	while (--i >= 0)
		ft_putchar((octet >> i & 1) + 48);
}
