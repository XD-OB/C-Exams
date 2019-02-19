#include <stdlib.h>

int		*ft_range(int start, int end)
{
	int		*tab;
	int		i;
	int		size;
	int		step;

	size = (start < end) ? (end - start + 1) : (start - end + 1);
	step = (start < end ) ? 1 : -1;
	tab = (int*)malloc(sizeof(int) * size);
	i = -1;
	while (++i < size)
		tab[i] = start + i * step;
	return (tab);
}
