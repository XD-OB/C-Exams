#include <stdio.h>
#include <stdlib.h>

char    *moment(unsigned int duration);

int	main(int argc, char *argv[])
{
	if (argc == 2)
	{
		char	*str;
	
		str = moment(atoi(argv[1]));
		printf("%s\n", str);	
		free(str);
	}
	return (0);
}
