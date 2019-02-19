#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_put_pos_nbr(int nbr)
{
	if (nbr > 9)
		ft_put_pos_nbr(nbr / 10);
	ft_putchar((nbr % 10) + 48);
}

int		main(int argc, char *argv[])
{
	(void)argv;
	ft_put_pos_nbr(argc - 1);
	ft_putchar('\n');
}
