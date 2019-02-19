#include <stdlib.h>

int		*ft_rrange(int start, int end)
{
	int		*tab;
	int		i;
	int		size;
	int		step;

	size = (start < end) ? (end - start + 1) : (start - end + 1);
	step = (start < end ) ? -1 : 1;
	tab = (int*)malloc(sizeof(int) * size);
	i = size;
	while (--i >= 0)
		tab[i] = end + i * step;
	return (tab);
}
