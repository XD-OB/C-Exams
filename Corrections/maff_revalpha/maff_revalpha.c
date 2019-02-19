#include <unistd.h>

void	ft_putchar(int c)
{
	write(1, &c, 1);
}

int		main(void)
{
	//write(1, "zYxWvUtSrQpOnMlKjIhGfEdCbA\n", 27);
	
	int		c;

	c = 'z';
	while (c >= 'a')
	{
		(c % 2 == 0) ? ft_putchar(c) : ft_putchar(c - 32);
		c--;
	}
	ft_putchar('\n');
	return (0);
}
