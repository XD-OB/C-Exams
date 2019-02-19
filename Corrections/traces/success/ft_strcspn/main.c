#include <stdio.h>
#include <string.h>

size_t	ft_strcspn(const char *s, const char *reject);

int main() {
	int	len;
	int	len_ft;
	const char str1[] = "ABCDEF4969410";
	const char str2[] = "C";

	len = strcspn(str1, str2);
	len_ft = ft_strcspn(str1, str2);
	printf("First matched character is at %d\n", len);
	printf("First matched character is at %d\n", len_ft);
	return (0);
}
