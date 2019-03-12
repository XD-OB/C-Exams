#include <unistd.h>
#include <stdlib.h>

#define BUFF_SIZE 2048

void	brainfuck(char *str)
{
	int		i;
	int		loop;
	char	*ptr;
	char	*tmp;

	if (!(ptr = (char*)malloc(sizeof(char) * (BUFF_SIZE + 1))))
		return ;
	tmp = ptr;
	i = -1;
	while (++i <= BUFF_SIZE)
		ptr[i] = '\0';
	while (*str)
	{
		(*str == '>') ? ptr += 1 : ptr;
		(*str == '<') ? ptr -= 1 : ptr;
		(*str == '+') ? *ptr += 1 : *ptr;
		(*str == '-') ? *ptr -= 1 : *ptr;
		if (*str == '.')
			write(1, ptr, 1);
		if (*str == '[' && !*ptr)
		{
			loop = 1;
			while (loop)
			{
				str++;
				if (*str == '[')
					loop++;
				if (*str == ']')
					loop--;
			}
		}
		if (*str == ']' && *ptr)
		{
			loop = 1;
			while (loop)
			{
				str--;
				if (*str == ']')
					loop++;
				if (*str == '[')
					loop--;
			}
		}
		str++;
	}
	free(tmp);
}

int		main(int argc, char *argv[])
{
	if (argc == 2)
		brainfuck(argv[1]);
	else
		write(1, "\n", 1);
	return (0);
}
