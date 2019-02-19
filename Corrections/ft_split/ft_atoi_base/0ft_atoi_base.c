void	ft_strrev(char *str)
{
	int		i = -1;
	int		j = 0;
	char	tmp;

	while (str[j])
		j++;
	while (++i < --j)
	{
		tmp = str[j];
		str[j] = str[i];
		str[i] = tmp;
	}
}

void	ft_to_upper(char *str)
{
	int		i = -1;

	while (str[++i])
		if (str[i] > 96 && str[i] < 123)
			str[i] -= 32;
}

void	ft_atoa(char *str, int base)
{
	int		i = 0;
	int		j = 0;
	char	tab[50];

	while (str[i]== 32 || (str[i]>= 9 && str[i]<= 13))
		i++;
	if (str[i] == '+')
		i++;
	if (str[i] == '-')
	{
		tab[j] = '-';
		i++;
		j++;
	}
	while (str[i])
	{
		if (str[i]>= 48 && str[i] < (base + 48) && base <= 10)
			tab[j++] = str[i++];
		else if (base > 10 && str[i]>= 48 && str[i]<= 57)
			tab[j++] = str[i++];
		else if (base > 10 && str[i]>= 65 && str[i]<= 70)
			tab[j++] = str[i++];
		else
			break;
	}
	tab[j] = '\0';
	i = 0;
	while (str[i])
		str[i++] = '\0';
	i = -1;
	while (tab[++i])
		str[i] = tab[i];
	str[i] = '\0';
	if (str[0] == '-' && !str[1])
		str[0] = '\0';
}

int		power(int a, int n)
{
	if (n == 0)
		return (1);
	while (--n > 0)
		a *= a;
	return (a);
}

int		ft_atoi_base(const char *nbr, unsigned int base)
{
	int		i = -1;
	int		j = 0;
	int		sign;
	int		result = 0;
	char	tab[50];

	while (nbr[++i])
		tab[i] = nbr[i];
	tab[i] = '\0';
	ft_to_upper(tab);
	ft_atoa(tab, base);
	sign = (tab[0] == '-') ? -1 : 1;
	ft_strrev(tab);
	i = 0;
	while (tab[i] && tab[i] != '-')
	{
		if (tab[i] <= 57 && tab[i] >= 48)
			result += (tab[i] - 48) * power(base, j);
		if (tab[i] <= 70 && tab[i] >= 65)
			result += (tab[i] - 65 + 10) * power(base, j);
		i++;
		j++;
	}
	return (result * sign);
}
