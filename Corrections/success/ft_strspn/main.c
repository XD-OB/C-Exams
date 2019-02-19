#include <stdio.h>
#include <string.h>

size_t	ft_strspn(const char *s, const char *accept);

int main() {
	int	len;
	int	len_ft;
	const char str1[] = "ABCDEF4969410";
	const char str2[] = "ABC";

	len = strspn(str1, str2);
	len_ft = ft_strspn(str1, str2);
	printf("strspn First matched character is at %d\n", len);
	printf("ft_strspn First matched character is at %d\n", len_ft);
	return (0);
}
