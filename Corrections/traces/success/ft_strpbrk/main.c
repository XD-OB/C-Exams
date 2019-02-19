#include <stdio.h>
#include <string.h>

char	*ft_strpbrk(const char *s1, const char *s2);

int	main() {
	const char	str1[] = "bcdef34ghijk1";
	const char	str2[] = "34a";
	char *ret;
	char *ret_ft;

	ret = strpbrk(str1, str2);
	ret_ft = ft_strpbrk(str1, str2);
	if (ret || ret_ft) {
		printf("strpbrk First matching character: %c\n", *ret);
		printf("ft_strpbrk First matching character: %c\n", *ret_ft);
	}
	else
		printf("Character not found\n");
	return (0);
}
