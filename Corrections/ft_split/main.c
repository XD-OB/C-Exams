#include <stdio.h>

char	**ft_split(char *str);

void	print_tab(char **tab)
{
	int		i;
	int		j;

	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
			printf("%c", tab[i][j++]);
		printf("\n");
		i++;
	}
}

int		main(int argc, char **argv)
{
	char	**tab;

	if (argc == 2)
	{
		tab = ft_split(argv[1]);
		print_tab(tab);
	}
	return (0);
}
