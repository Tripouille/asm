#include <stdio.h>
#include <string.h>

size_t		ft_strlen(const char *s);

int main()
{
	char	*s = "123456789";
	printf("Test de ft_strlen:\n");
	printf("[Orig: %lu / Ours: %lu] String = \"%s\"\n", strlen(s), ft_strlen(s), s);
	s += 4;
	printf("[Orig: %lu / Ours: %lu] String = \"%s\"\n", strlen(s), ft_strlen(s), s);
	s += 5;
	printf("[Orig: %lu / Ours: %lu] String = \"%s\"\n", strlen(s), ft_strlen(s), s);


	printf("Test de ft_strcpy:\n");
	return (0);
}
