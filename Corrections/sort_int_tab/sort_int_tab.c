#include <stdio.h>

void sort_int_tab(int *tab, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	int				count;
	int				tmp;

	i = -1;
	count = 1;
	while (count && ++i < size - 1)
	{
		count = 0;
		j = -1;
		while (++j < size - 1)
		{
			if (tab[j + 1] < tab[j])
			{
				count++;
				tmp = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = tmp;
			}
		}
	}
}
