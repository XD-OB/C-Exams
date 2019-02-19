#include <unistd.h>
#include <stdlib.h>

#define BUFF_SIZE 2048

void	brainfuck(char *str)
{
	char	*array;
	char	*ptr;
	int		loop;
	int		i;

	ptr = (char*)malloc(sizeof(char) * (BUFF_SIZE + 1));
	array = ptr;
	i = -1;
	while (++i <= BUFF_SIZE)
		ptr[i] = '\0';
	i = 0;
	while (str[i]) {
		(str[i] == '>') ? ptr += 1 : ptr;
		(str[i] == '<') ? ptr -= 1 : ptr;
		(str[i] == '+') ? *ptr += 1 : *ptr;
		(str[i] == '-') ? *ptr -= 1 : *ptr;
		if (str[i] == '.')
			write(1, ptr, 1);
		if (str[i] == '[' && !*ptr) {
			loop = 1;
			while (loop) {
				i++;
				(str[i] == '[') ? loop++ : loop;
				(str[i] == ']') ? loop-- : loop;
			}
		}
		if (str[i] == ']' && *ptr) {
			loop = 1;
			while (loop) {
				i--;
				(str[i] == '[') ? loop-- : loop;
				(str[i] == ']') ? loop++ : loop;
			}
		}
		i++;
	}
	free(array);
}

int		main(int argc, char *argv[])
{
	if (argc == 2)
		brainfuck(argv[1]);
	else
		write(1, "\n", 1);
	return (0);
}
