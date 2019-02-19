#include <unistd.h>

int		main(int argc, char *argv[])
{
	int		len = 0;
	int		i = 0;

	if (argc == 3)
	{
		while (argv[1][len])
			len++;
		while (*argv[2] && i < len) {
			if (*argv[2] == argv[1][i])
				i++;
			argv[2]++;
		}
		if (i == len)
			write(1, argv[1], len);
	}
	write(1, "\n", 1);
	return (0);
}
