#include <stdio.h>

int		is_blank(char c)
{
	return (c == 32 || (c >= 9 && c <= 13));
}

int		ft_atoi(const char *str)
{
	int		result = 0;
	int		sign;

	while(is_blank(*str))
		str++;
	sign = (*str == '-') ? -1 : 1;
	(*str == '-' || *str == '+') ? str++ : 0;
	while (*str && *str >= 48 && *str <= 57)
	{
		result = (result * 10) + (*str - 48);
		str++;
	}
	return (result * sign);
}

int		main(int argc, char *argv[])
{
	if (argc == 2)
		printf("%d\n", ft_atoi(argv[1]));
	return (0);
}
