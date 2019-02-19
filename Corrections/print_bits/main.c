#include <stdio.h>

void	print_bits(unsigned char octet);

int main()
{
	int octet = 0b10010011;
	print_bits(octet);
	printf("\n");
	return (0);
}
