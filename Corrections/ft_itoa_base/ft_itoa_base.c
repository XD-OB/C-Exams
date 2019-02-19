#include <stdlib.h>

void	ft_strrev(char *str)
{
	int		i;
	int		j;
	char	tmp;

	j = 0;
	while (str[j])
		j++;
	i = -1;
	while (++i < --j)
	{
		tmp = str[j];
		str[j] = str[i];
		str[i] = tmp;
	}
}

char	*ft_itoa_base(int value, int base)
{
	long	nb;
	int		i;
	int		size;
	int		sign;
	char	*result;

	sign = (value < 0 && base == 10) ? -1 : 1;
	size = (sign == -1) ? 2 : 1;
	nb = (value < 0) ? -(long)value : value;
	while (nb /= base)
		size++;
	result = (char*)malloc(sizeof(char) * (size + 1));
	result[size] = '\0';
	nb = (value < 0) ? -(long)value : value;
	i = 0;
	if (sign == -1)
	{
		result[i] = '-';
		i++;
	}
	while (i < size)
	{
		result[i] = (nb % base < 10) ? (nb % base + '0') : (nb % base - 10 + 'A');
		nb /= base;
		i++;
	}
	(result[0] == '-') ? ft_strrev(&result[1]) : ft_strrev(result);
	return (result);
}
