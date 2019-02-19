#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "t_point.h"

void  flood_fill(char **tab, t_point size, t_point begin);

char **make_area(char **zone, t_point size)
{
	char **area;
	int		i = 0;

	area = (char**)malloc(sizeof(char*) * (size.y + 1));
	area[size.y] = 0;
	while (i < size.y)
	{
		area[i] = strdup(zone[i]);
		i++;
	}
	return (area);
}

void	print_tab(char **tab)
{
	while (*tab)
	{
		printf("%s\n", *tab);
		tab++;
	}
}

int main(void)
{
	char **area;
	t_point size = { 5, 5 };
	t_point begin = { 1, 1 };
	char *zone[] = {
		"00000",
		"10111",
		"11011",
		"11101",
		"11110"
	};

	area = make_area(zone, size);
	print_tab(area);
	flood_fill(area, size, begin);
	printf("\n");
	print_tab(area);
	return (0);
}
