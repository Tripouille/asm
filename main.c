#include <stdio.h>
#include <string.h>

size_t		ft_strlen(const char *s);
char		*ft_strcpy(char *dst, const char *src);
int			ft_strcmp(const char *s1, const char *s2);

int main()
{
	char	*s = "A23456789";
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

	printf("\nTest de ft_strcmp:\n");
	s -= 9;
	printf("\n[Orig: %i / Ours: %i] String = '%s'\n", strcmp(s, "A23456"), ft_strcmp(s, "A23456"), s);
	printf("\n[Orig: %i / Ours: %i] String = '%s'\n", strcmp(s, "A23458"), ft_strcmp(s, "A23458"), s);
	s = "123\12 2";
	printf("\n[Orig: %i / Ours: %i] String = '%s'\n", strcmp(s, "123\12 4"), ft_strcmp(s, "123\12 4"), s);
	
	return (0);
}
