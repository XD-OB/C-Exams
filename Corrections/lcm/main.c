#include <stdlib.h>
#include <stdio.h>

unsigned int	pgcd(unsigned int a, unsigned int b);
unsigned int	lcm(unsigned int a, unsigned int b);

int		main(int ac, char **av)
{
	if (ac == 3)
	{
		printf("lcm : %d\n", lcm(atoi(av[1]), atoi(av[2])));
		printf("pgcd: %d\n", pgcd(atoi(av[1]), atoi(av[2])));
	}
	return (0);
}
