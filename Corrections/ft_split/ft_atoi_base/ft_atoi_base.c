int		is_blank(char c)
{
	return (c == 32 || (c >= 9 && c <= 13));
}

int		is_valid(char c, int base)
{
	if (c >= 48 && c <= 48 + (base - 1) && base <= 16)
		return (1);
	if (((c >= 65 && c <= 65 - 10 + (base - 1)) || (c >= 97 && c <= 97 - 10 + (base - 1)))
		&& (base > 10 && base <= 16))
		return (1);
	return (0);
}

int		get_value(char c)
{
	if (c >= 48 && c<= 57)
		return (c - 48);
	if (c >= 65 && c <= 70)
		return (c - 65 + 10);
	return (c - 97 + 10);
}

int		ft_atoi_base(const char *nbr, unsigned int base)
{
	int		sign;
	int		result = 0;

	while (is_blank(*nbr))
		nbr++;
	sign = (*nbr == '-') ? -1 : 1;
	(*nbr == '-' || *nbr == '+') ? nbr++ : 0;
	while (is_valid(*nbr, base))
		result = (result * base) + get_value(*nbr++);
	return (result * sign);
}
