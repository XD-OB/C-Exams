#include <unistd.h>

unsigned char	swap_bits(unsigned char	byte);

void	print_bits(unsigned char byte) {
	int	i = 256;

	while (i >>= 1)
		(byte & i) ? write(1, "1", 1) : write(1, "0", 1);
}

int		main() {
	unsigned char	byte;

	byte = 0b10100101;
	print_bits(byte);
	write(1, "\n", 1);
	byte = swap_bits(byte);
	print_bits(byte);
	write(1, "\n", 1);
	return (0);
}
