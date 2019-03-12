#include <stdio.h>
#include <stdlib.h>

int		*ft_rrange(int start, int end);

void	print_tab(int *tab, int size)
{
	int	i = -1;

	while (++i < size)
		printf("%d\n", tab[i]);
}

int		main(int argc, char *argv[])
{
	int		start, end;
	int		size;

	if (argc == 3 || argc == 4)
	{
		start = atoi(argv[1]);
		end = atoi(argv[2]);
		if (argc == 4)
			size = atoi(argv[3]);
		else
			size = (start < end) ? end - start + 1 : start - end + 1;
		print_tab(ft_rrange(start, end), size);
	}
	printf("\n");
	return (0);
}
