#include <stdio.h>

void sort_int_tab(int *tab, unsigned int size);

int		main(void)
{
	int	tab[] = {13, 9, 20, 118};
	int	i;

	i = -1;
	while (++i < 4)
		printf("%d ", tab[i]);
	printf("\n");
	sort_int_tab(tab, 4);
	i = -1;
	while (++i < 4)
		printf("%d ", tab[i]);
	printf("\n");
	return (0);
}
