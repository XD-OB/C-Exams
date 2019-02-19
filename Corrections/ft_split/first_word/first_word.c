#include <unistd.h>

int	main(int argc, char *argv[])
{
	if (argc == 2)
	{
		while (*argv[1] && (*argv[1] == 32 || *argv[1] == 9))
			argv[1]++;
		while (*argv[1] && *argv[1] != 32 && *argv[1] != 9)
			write(1, argv[1]++, 1);
	}
	write(1, "\n", 1);
}
