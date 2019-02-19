int		is_blank(char c)
{
	return (c == 32 || c == 9);
}

int		is_valid(char c, int base)
{
	return ((c >= 48 && c <= 48 + base - 1 && base <= 10)
			|| (((c >= 48 && c <= 57)
			|| (c >= 65 && c <= 65 - 10 + (base - 1))
			|| (c >= 97 && c <= 97 - 10 + (base - 1))) && (base > 10 && base <= 16)));
}

int		get_value(char c)
{
	if (c >= 48 && c <= 57)
		return (c - 48);
	if (c >= 65 && c <= 70)
		return (c - 65 + 10);
	return (c - 97 + 10);
}

int		ft_atoi_base(const char *nbr, unsigned int base)
{
	int		ret = 0;
	int		sign;

	while (is_blank(*nbr))
		nbr++;
	sign = (*nbr == '-') ? -1 : 1;
	(*nbr == '-' || *nbr == '+') ? nbr++ : 0;
	while (is_valid(*nbr, base))
	{
		ret = (ret * base) + get_value(*nbr);
		nbr++;
	}
	return (ret * sign);
}
