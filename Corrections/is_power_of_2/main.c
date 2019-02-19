#include <stdio.h>
#include <stdlib.h>

int		is_power_of_2(unsigned int n);

int		main(int argc, char *argv[]) {
	int		i;
	int		var;

	if (argc > 1)
	{	i = 0;
		while (++i < argc)
		{
			var = atoi(argv[i]);
			if (is_power_of_2(var))	
				printf("%d is power of 2\n\n", var);
			else
				printf("%d is not power of 2\n\n", var);
		}
	}
	return (0);
}
