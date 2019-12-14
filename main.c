#include <stdio.h>
#include <string.h>

size_t		ft_strlen(const char *s);
char		*ft_strcpy(char *dst, const char *src);

int main()
{
	char	*s = "123456789";
	printf("Test de ft_strlen:\n");
	printf("[Orig: %lu / Ours: %lu] String = '%s'\n", strlen(s), ft_strlen(s), s);
	s += 4;
	printf("[Orig: %lu / Ours: %lu] String = '%s'\n", strlen(s), ft_strlen(s), s);
	s += 5;
	printf("[Orig: %lu / Ours: %lu] String = '%s'\n", strlen(s), ft_strlen(s), s);

	printf("\nTest de ft_strcpy:\n");
	char	s_orig[100];
	char	s_ours[100];
	char	*ret;
	s -= 9;
	strcpy(s_orig, s);
	ret = ft_strcpy(s_ours, s);
	printf("[Orig: '%s' / Ours: '%s'] / [dest = %p return = %p]\n", s_orig, s_ours, s_ours, ret);
	s += 4;
	strcpy(s_orig, s);
	ret = ft_strcpy(s_ours, s);
	printf("[Orig: '%s' / Ours: '%s'] / [dest = %p return = %p]\n", s_orig, s_ours, s_ours, ret);
	s += 5;
	strcpy(s_orig, s);
	ret = ft_strcpy(s_ours, s);
	printf("[Orig: '%s' / Ours: '%s'] / [dest = %p return = %p]\n", s_orig, s_ours, s_ours, ret);
	return (0);
}
