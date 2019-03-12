void	sort_int_tab(int *tab, unsigned int size)
{
	unsigned int	i = -1;
	unsigned int	j;
	int		tmp;
	int		sorted = 0;

	while (++i < size - 1 && !sorted)
	{
		sorted = 1;
		j = -1;
		while (++j < size - 1)
		{
			if (tab[j + 1] < tab[j])
			{
				sorted = 0;
				tmp = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = tmp;
			}
		}
	}
}
