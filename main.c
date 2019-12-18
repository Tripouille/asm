#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

size_t		ft_strlen(const char *s);
char		*ft_strcpy(char *dst, const char *src);
int			ft_strcmp(const char *s1, const char *s2);
ssize_t		ft_write(int fildes, const void *buf, size_t nbyte);

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
	printf("\n[Orig: %i / Ours: %i] String = '%s'\n", strcmp("123", "123"), ft_strcmp("123", "123"), s);
	printf("\n[Orig: %i / Ours: %i] String = '%s'\n", strcmp(s, ""), ft_strcmp(s, ""), s);

	printf("\nTest de ft_write:\n");
	printf("\n[Orig: %zi / Ours: %zi] String = '%s'\n", write(1, "salut\n", 6), ft_write(1, "salut\n", 6), "salut\n");
	printf("\n[Orig: %zi / Ours: %zi] String = '%s'\n", write(1, "salut\n", 0), ft_write(1, "salut\n", 0), "salut\n");
	int		fd = open("test.txt", O_RDWR | O_CREAT, 0600);
	ft_write(fd, "salut", 5);
	ft_write(fd, " ca va", 6);

	return (0);
}
