#include <stdio.h>
#include <stdlib.h>

int		ft_atoi_base(char *str, int base);

int		main(int argc, char **argv)
{
	if (argc == 3)
		printf("%d\n", ft_atoi_base(argv[1], atoi(argv[2])));
	return (0);
}
