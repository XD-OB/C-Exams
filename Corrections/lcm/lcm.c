unsigned int	pgcd(unsigned int a, unsigned int b)
{
	unsigned int	pgcd;

	pgcd = (a < b) ? a : b;
	while (pgcd > 0 && (a % pgcd != 0 || b % pgcd != 0))
		pgcd--;
	return (pgcd);
}

unsigned int	lcm(unsigned int a, unsigned int b)
{
	unsigned int	lcm;

	if (pgcd(a, b) == 0)
		return (0);
	lcm = (a * b) / pgcd(a, b);
	return (lcm);
}
