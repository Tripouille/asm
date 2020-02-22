/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgambard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 23:58:05 by jgambard          #+#    #+#             */
/*   Updated: 2020/02/22 02:03:30 by jgambard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgambard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 10:37:47 by jgambard          #+#    #+#             */
/*   Updated: 2020/02/21 23:57:55 by jgambard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include "list.h"

size_t		ft_strlen(const char *s);
char		*ft_strcpy(char *dst, const char *src);
int			ft_strcmp(const char *s1, const char *s2);
ssize_t		ft_write(int fildes, const void *buf, size_t nbyte);
ssize_t		ft_read(int fildes, void *buf, size_t nbyte);
char		*ft_strdup(const char *s1);
int			ft_cinstr(char c, char *str);
int			ft_atoi_base(char *str, char *base);
t_list		*ft_create_elem(void *data);
void		ft_list_push_front(t_list **begin_list, void *data);
int			ft_list_size(t_list *begin_list);
void		ft_list_sort(t_list **begin_list, int (*cmp)());
void		ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(),
								void (*free_fct)(void *));

void	show_list(t_list *list)
{
	int		i;

	i = 0;
	while (list && i < 5)
	{
		//printf("list[%i] = %d\n", i, ((int*)list->data)[0]);
		printf("list[%i] = %p\n", i, list);
		list = list->next;
		i++;
	}
	printf("end of show list\n\n");
}

int		compare_pointers(int *a, int *b)
{
	return (0);
	return (*a == *b ? 0 : 1);
}

int		compare(int a, int b)
{
	//printf("comparing %d to %d\n", a, b);
	return (a - b);
}

int main()
{
	errno = 0;
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
	printf("[Orig: %i / Ours: %i] String = '%s'\n", strcmp(s, "A23456"), ft_strcmp(s, "A23456"), s);
	printf("[Orig: %i / Ours: %i] String = '%s'\n", strcmp(s, "A23458"), ft_strcmp(s, "A23458"), s);
	s = "123\18 2";
	printf("[Orig: %i / Ours: %i] String = '%s'\n", strcmp(s, "123\18 4"), ft_strcmp(s, "123\18 4"), s);
	printf("[Orig: %i / Ours: %i] String = '%s'\n", strcmp("123", "123"), ft_strcmp("123", "123"), s);
	printf("[Orig: %i / Ours: %i] String = '%s'\n", strcmp(s, ""), ft_strcmp(s, ""), s);

	int		ours;
	int		orig;
	char	*str = "salut";

	printf("\nTest de ft_write:\n");

	printf("Test avec : %s\n", str);
	dprintf(2, "Orig : ");
	orig = write(1, str, 5);
	printf("\nreturn : %i\n", orig);
	dprintf(2, "Ours : ");
	ours = ft_write(1, str, 5);
	printf("\nreturn : %i\n", ours);
	system("rm  test.txt");
	int		fd = open("test.txt", O_RDWR | O_CREAT | O_TRUNC, 0600);
	ft_write(fd, "salut", 5);
	ft_write(fd, " ca va", 6);
	printf("Test de ft_write dans un fd:\n");
	system("cat test.txt");

	printf("\nTest d'errno dans ft_write (9):\n");
	ft_write(546456, "dff", 25);
	printf("errno = %i\n", errno);
	close(fd);

	fd = open("test.txt", O_RDWR | O_CREAT, 0600);
	char	orig_buffer[100];
	char	our_buffer[100];
	printf("\nTest de ft_read:\n");
	orig_buffer[read(fd, orig_buffer, 2)] = 0;
	printf("orig buffer : %s\n", orig_buffer);
	close(fd);
	fd = open("test.txt", O_RDWR | O_CREAT, 0600);
	our_buffer[ft_read(fd, our_buffer, 2)] = 0;
	printf("our buffer : %s\n", our_buffer);
	close(fd);

	printf("\nTest de ft_strdup:\n");
	str = "salutations";
	char	*orig_str = strdup(str);
	char	*ours_str = ft_strdup(str);
	printf("base : %p, origin : %p '%s', ours : %p '%s'\n", str, orig_str, orig_str, ours_str, ours_str);
	free(orig_str);
	free(ours_str);

	printf("\nTest de ft_atoi_base:\n");
	char	*atoi_str	= "          \11\12\13\14\15  -+-2147483648";
	char	*base		= "0123456789";
	printf("str = [%s] base = [%s] result = [%d]\n", atoi_str, base, ft_atoi_base(atoi_str, base));
	atoi_str = "           -+-0";
	printf("str = [%s] base = [%s] result = [%d]\n", atoi_str, base, ft_atoi_base(atoi_str, base));
	atoi_str = "           -++++-1";
	printf("str = [%s] base = [%s] result = [%d]\n", atoi_str, base, ft_atoi_base(atoi_str, base));
	atoi_str = "-1";
	printf("str = [%s] base = [%s] result = [%d]\n", atoi_str, base, ft_atoi_base(atoi_str, base));
	atoi_str = "001";
	printf("str = [%s] base = [%s] result = [%d]\n", atoi_str, base, ft_atoi_base(atoi_str, base));
	atoi_str = "00100";
	base = "0123456789abcdef";
	printf("str = [%s] base = [%s] result = [%d]\n", atoi_str, base, ft_atoi_base(atoi_str, base));
	atoi_str = "00100";
	base = "01";
	printf("str = [%s] base = [%s] result = [%d]\n", atoi_str, base, ft_atoi_base(atoi_str, base));
	atoi_str = "-00100";
	printf("str = [%s] base = [%s] result = [%d]\n", atoi_str, base, ft_atoi_base(atoi_str, base));
	atoi_str = "-00100";
	base = "0";
	printf("str = [%s] base = [%s] result = [%d]\n", atoi_str, base, ft_atoi_base(atoi_str, base));
	atoi_str = "-00100";
	base = "011";
	printf("str = [%s] base = [%s] result = [%d]\n", atoi_str, base, ft_atoi_base(atoi_str, base));
	atoi_str = "-00100";
	base = "01-";
	printf("str = [%s] base = [%s] result = [%d]\n", atoi_str, base, ft_atoi_base(atoi_str, base));
	atoi_str = "-00100";
	base = "01+";
	printf("str = [%s] base = [%s] result = [%d]\n", atoi_str, base, ft_atoi_base(atoi_str, base));
	atoi_str = "-00100";
	base = "01 ";
	printf("str = [%s] base = [%s] result = [%d]\n", atoi_str, base, ft_atoi_base(atoi_str, base));

	int		*tab[5];
	int		i = -1;
	while (++i < 5)
		tab[i] = malloc(4);
	*tab[0] = 30;
	*tab[1] = -9;
	*tab[2] = 5;
	*tab[3] = -9;
	*tab[4] = -16;
	printf("\nTest sur la liste:\n");
	t_list	*new = 0;
	printf("size de la list = %i\n", ft_list_size(new));
	ft_list_push_front(&new, tab[0]);
	show_list(new);
	printf("size de la list = %i\n", ft_list_size(new));
	ft_list_push_front(&new, tab[1]);
	show_list(new);
	printf("size de la list = %i\n", ft_list_size(new));
	ft_list_push_front(&new, tab[2]);
	ft_list_push_front(&new, tab[3]);
	ft_list_push_front(&new, tab[4]);
	printf("list before sort :\n");
	show_list(new);
	ft_list_sort(&new, &compare);
	printf("list after sort :\n");
	show_list(new);

	int		ref = -9;
	printf("removing all %i from the list (new = %p)\n", ref, new);
	ft_list_remove_if(&new, &ref, &compare_pointers, &free);
	printf("list after removing : (new = %p)\n", new);
	show_list(new);

	new = 0;
	while (1);
	return (0);
}
