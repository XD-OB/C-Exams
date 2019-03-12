#include <stdlib.h>

int		*ft_rrange(int start, int end)
{
	int		i;
	int		size;
	int		step;
	int		*tab;

	size = (start < end) ? (end - start + 1) : (start - end + 1);
	step = (start < end) ? -1 : 1;
	tab = (int*)malloc(sizeof(int) * size);
	i = -1;
	while (++i < size)
		tab[i] = end + i * step;
	return (tab);
}
