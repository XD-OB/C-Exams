#include <unistd.h>

int		ft_strlen(char *str)
{
	int		i = 0;

	while (str[i])
		i++;
	return (i);
}

void	print_pal(char *str, int start, int maxlen)
{
		write(1, &str[start], maxlen);
}

void	biggest_pal(char *str)
{
	int		i;
	int		len;
	int		low, high;
	int		start;
	int		maxlen;

	i = 0;
	maxlen = 1;
	len = ft_strlen(str);
	start = len - 1;
	while (++i < len)
	{
		low = i - 1;
		high = i + 1;
		while (low >= 0 && high < len && str[low] == str[high])
		{
			if (high - low + 1 >= maxlen)
			{	
				start = low;
				maxlen = high - low + 1;
			}
			high++;
			low--;
		}
		low = i - 1;
		high = i;
		while (low >= 0 && high < len && str[low] == str[high])
		{
			if (high - low + 1 >= maxlen)
			{
				start = low;
				maxlen = high - low + 1;
			}
			high++;
			low--;
		}
	}
	print_pal(str, start, maxlen);
}

int		main(int argc, char *argv[])
{
	if (argc == 2)
		biggest_pal(argv[1]);
	write(1, "\n", 1);
	return (0);
}
