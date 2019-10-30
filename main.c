/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttampio <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 09:59:56 by ttampio           #+#    #+#             */
/*   Updated: 2019/10/30 10:33:21 by ttampio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define BLUE "\033[1;36m"
#define YELLOW "\033[1;33m"
#define GREEN "\033[1;32m"
#define RED "\033[0;31m"
#define MAGENTA "\033[0;35m"
#define RESET "\033[0m"

#include <stdio.h>
#include "libft.h"
#include <string.h>
#include <fcntl.h>
#include <ctype.h>

t_list	*ft_test_lstmap(t_list *node)
{
	t_list	*new_node;
	char	*s;
	size_t	i;

	s = ft_strdup(node->content);
	i = 0;
	while (s[i])
	{
		if (s[i] >= 'a' && s[i] <= 'z' )
			s[i] = ft_toupper(s[i]);
		i++;
	}
	new_node = ft_lstnew(s, node->content_size);
	return (new_node);
}

void	ft_test_lstiter(t_list *node)
{
	printf("%s  -->%s Running ft_test_lstiter\n", RED, RESET);
	printf("%s  -->%s Node content: '%s'\n", YELLOW, RESET, node->content);
	printf("%s  -->%s Node content_size: '%zu'\n", YELLOW, RESET, node->content_size);

}

t_list	*ft_init_list(void)
{
	t_list	*node1;
	t_list	*node2;
	t_list	*node3;
	t_list	*node4;

	node1 = ft_lstnew(ft_strdup("First node"), sizeof("First node"));
	node2 = ft_lstnew(ft_strdup("Second node"), sizeof("Second node"));
	node3 = ft_lstnew(ft_strdup("Third node"), sizeof("Third node"));
	node4 = ft_lstnew(ft_strdup("Fourth node"), sizeof("Fourth node"));

	node1->next = node2;
	node2->next = node3;
	node3->next = node4;

	return (node1);
}

void	ft_print_list(t_list *list)
{
	printf("%s  Printing nodes:%s\n", GREEN, RESET);
	while (list)
	{

		printf("%s  %s\n%s", YELLOW, list->content, RESET);
		list = list->next;
	}
	printf("\n");
}

void	ft_del(void *content, size_t size)
{
	printf("TEST CONTENT_SIZE IN DEL %zu\n", size);
	printf("TEST VALUE IN DEL %s\n", (char*)content);
	free(content);
	content = NULL;
}

void	ft_print_color(char *color, char *s)
{
	printf("%s", color);
	printf("%s", s);
	printf("%s", RESET);
}

void	ft_print_ci(unsigned int i, char *s)
{
	printf("Running ft_print_ci! ");
	printf("character %c at index %d\n", *s, i);
}

char	ft_print_strmapi_test(unsigned int i, char c)
{
	printf("Running ft_print_ci! ");
	printf("character %c at index %u\n", c, i);
	return (c);
}

void	ft_print_header(char *header, char *color)
{
	printf("%s", color);
	printf("\n----|\n");
	printf("----| %s\n", header);
	printf("----|\n\n");
	printf("%s", RESET);

}

void	ft_test_mem(void *ptr, size_t size, int c, int line)
{
	size_t			i = 0;
	unsigned char	*test_ptr;

	test_ptr = (unsigned char*)ptr;
	while (i < size - 1)
	{
		if (test_ptr[i] != c)
		{
			printf("%s", RED);
			printf("    FOUND SOMETHING OTHER THAN '%d', LINE: %d\n", c, line);
			printf("    INDEX POSITION %zu\n", i);
			printf("%s", RESET);
			abort();
		}
		i++;
	}
}

void	ft_print_run_cmd(char *cmd)
{
	printf("%s  -->%s  RUNNING COMMAND: '%s'\n\n", RED, RESET, cmd);
}

void	printArray(int arr[], int n)
{
	for (int i=0; i<n; i++)
		printf("%d ", arr[i]);
}

void	ft_print_result(char *description, char *res)
{
	printf("%s", GREEN);
	printf("  RESULT (%s): '%s'\n\n", description, res);
	printf("%s", RESET);
}

void	ft_print_test_strings(char *origin, char *str1, char *str2, char *str1_name, char *str2_name)
{
	printf(" %s\n", origin);
	printf("\033%s", YELLOW);
	printf("  %s(%zu): '%s'\n", str1_name, strlen(str1), str1);
	printf("  %s(%zu): '%s'\n\n", str2_name, strlen(str2), str2);
	printf("\033[0m");
}

void	ft_print_test_string(char *origin, char *str1, char *str1_name)
{
	printf(" %s\n", origin);
	printf("\033%s", YELLOW);
	printf("  %s(%zu): '%s'\n\n", str1_name, strlen(str1), str1);
	printf("\033[0m");
}

void ft_print_func_name(char *name, char *color)
{
	printf("%s", color);
	printf("\n    ---- %s ----    \n\n", name);
	printf("%s", RESET);
}

/*
void	ft_is_something_test(char c1, char c2, char *func_name, int (*org_f)(int), int (*f_mine)(int))
{
	ft_print_func_name(func_name, BLUE);
	//printf("\033%s", YELLOW);
	printf("  Character to test: '%s\n'", c1);
	//printf("\033[0m");
	//printf("\033%s", GREEN);
	//printf(" ORG\n  RESULT (INT): %d\n", org_f(c1));
	printf("  RESULT (INT): %d\n", f_mine(c1));
	//printf("\033[0m");

	//printf("\033%s", YELLOW);
	printf("  Character to test: '%s\n'", c2);
	//printf("\033[0m");
	//printf("\033%s", GREEN);
	//printf(" ORG\n  RESULT (INT): %d\n", org_f(c2));
	printf("  RESULT (INT): %d\n", f_mine(c2));
	//printf("\033[0m");
}
*/

void ft_reset_strings(char *str1, char *str2, int fill_1, int fill_2)
{
	bzero(str1, 100);
	bzero(str2, 100);
	if (fill_1 == 1)
		strcpy(str1, "This is a test string one!");
	else if (fill_1 == 2)
		strcpy(str1, "This is a longer test string one! It has two awesome sentences.");
	if (fill_2 == 1)
		strcpy(str2, "Thus is a test string two!");
	else if (fill_2 == 2)
		strcpy(str2, "Thus is a longer test string two! It has two incredible sentences.");
}

int	main(void)
{
	t_list	*lst;

	char	str1[100] = "This is a test string one!";
	char	str2[100] = "Thus is a test string two!";
	size_t	i = 0;
	char	needle[] = "awesome";
	void	*v_ptr = NULL;
	char	*c_ptr = NULL;
	int		*i_ptr = NULL;


	printf("---- TESTS START----\n");

	ft_print_header("PART 1 - LIBC FUNCTIONS", YELLOW);

	// FT_BZERO
	ft_print_func_name("FT_BZERO", BLUE);
	ft_print_test_string("ORG", str1, "STR");
	ft_print_run_cmd("bzero(STR, 15)");
	bzero(str1, 15);
	ft_print_result("STR+15", str1+15);
	ft_print_result("STR=14", str1+14);


	ft_reset_strings(str1, str2, 1, 1);

	ft_print_test_string("MINE", str1, "STR");
	ft_print_run_cmd("ft_bzero(STR, 15)");
	ft_bzero(str1, 15);
	ft_print_result("STR+15", str1+15);
	ft_print_result("STR+14", str1+14);

	ft_reset_strings(str1, str2, 1, 1);

	// FT_MEMSET
	ft_print_func_name("FT_MEMSET", BLUE);
	printf("\n  ORG Before memset(): %s\n", str1);
	memset(str1, '.', 8*sizeof(char));
	printf("  ORG After memset():  %s", str1);
	printf("\n\n  MINE Before memset(): %s\n", str2);
	ft_memset(str2, '.', 8*sizeof(char));
	printf("  MINE After memset():  %s\n", str2);

	ft_reset_strings(str1, str2, 1, 1);

	// FT_MEMCPY
	ft_print_func_name("FT_MEMCPY", BLUE);
	printf("  ORG SRC(%lu) BEFORE memcpy(): %s\n", sizeof(str1), str1);
	printf("  ORG DST(%lu) BEFORE memcpy(): %s\n", sizeof(str2), str2);
	ft_print_run_cmd("memcpy(DST, SRC, 26)");
	printf("  RETURN VALUE: %s\n", memcpy(str2, str1, 26));
	printf("  ORG SRC(%lu) AFTER memcpy(): %s\n", sizeof(str1), str1);
	printf("  ORG DST(%lu) AFTER memcpy(): %s\n\n", sizeof(str2), str2);

	ft_reset_strings(str1, str2, 1, 1);

	printf("  MINE SRC(%lu) BEFORE ft_memcpy(): %s\n", sizeof(str1), str1);
	printf("  MINE DST(%lu) BEFORE ft_memcpy(): %s\n", sizeof(str2), str2);
	ft_print_run_cmd("ft_memcpy(DST, SRC, 26)");
	printf("  RETURN VALUE: %s\n", ft_memcpy(str2, str1, 26));
	printf("  MINE SRC(%lu) AFTER ft_memcpy(): %s\n", sizeof(str1), str1);
	printf("  MINE DST(%lu) AFTER ft_memcpy(): %s\n\n", sizeof(str2), str2);

	ft_reset_strings(str1, str2, 1, 1);

	// FT_MEMCCPY
	ft_print_func_name("FT_MEMCCPY", BLUE);
	printf("  ORG SRC(%lu) BEFORE memcpy(): %s\n", sizeof(str1), str1);
	printf("  ORG DST(%lu) BEFORE memcpy(): %s\n", sizeof(str2), str2);
	ft_print_run_cmd("memccpy(DST, SRC, 'a', 26)");
	printf("  RETURN VALUE: %s\n", memccpy(str2, str1, 'a', 26));
	printf("  ORG SRC(%lu) AFTER memcpy(): %s\n", sizeof(str1), str1);
	printf("  ORG DST(%lu) AFTER memcpy(): %s\n\n", sizeof(str2), str2);

	ft_reset_strings(str1, str2, 1, 1);

	printf("  MINE SRC(%lu) BEFORE ft_memcpy(): %s\n", sizeof(str1), str1);
	printf("  MINE DST(%lu) BEFORE ft_memcpy(): %s\n", sizeof(str2), str2);
	ft_print_run_cmd("ft_memccpy(DST, SRC, 'a', 26)");
	printf("  RETURN VALUE: %s\n", ft_memccpy(str2, str1, 'a', 26));
	printf("  MINE SRC(%lu) AFTER ft_memcpy(): %s\n", sizeof(str1), str1);
	printf("  MINE DST(%lu) AFTER ft_memcpy(): %s\n\n", sizeof(str2), str2);

	ft_reset_strings(str1, str2, 1, 1);

	// FT_MEMMOVE	
	ft_print_func_name("FT_MEMMOVE", BLUE);
	printf("  ORG SRC(%lu) BEFORE memmove(): %s\n", sizeof(str1), str1);
	printf("  ORG DST(%lu) BEFORE memmove(): %s\n", sizeof(str1), str1+5);
	ft_print_run_cmd("memmove(DST+5, SRC, 10)");
	printf("  RETURN VALUE: %s\n", memmove(str1+5, str1, 10));
	printf("  ORG SRC(%lu) AFTER memmove(): %s\n", sizeof(str1), str1);
	printf("  ORG DST(%lu) AFTER memmove(): %s\n\n", sizeof(str1), str1+5);

	ft_reset_strings(str1, str2, 1, 1);
	
	printf("  MINE SRC(%lu) BEFORE ft_memmove(): %s\n", sizeof(str1), str1);
	printf("  MINE DST(%lu) BEFORE ft_memmove(): %s\n", sizeof(str1), str1+5);
	ft_print_run_cmd("ft_memmove(DST+5, SRC, 10)");
	printf("  RETURN VALUE: %s\n", ft_memmove(str1+5, str1, 10));
	printf("  MINE SRC(%lu) AFTER ft_memmove(): %s\n", sizeof(str1), str1);
	printf("  MINE DST(%lu) AFTER ft_memmove(): %s\n\n", sizeof(str1), str1+5);

	ft_reset_strings(str1, str2, 1, 1);

	// FT_MEMCHR
	ft_print_func_name("FT_MEMCHR", BLUE);
	ft_print_test_string("ORG", str1, "STRING");
	ft_print_run_cmd("memchr(str1, 'a', 400)");
	ft_print_result("STRING", memchr(str1, 'a', 400));

	ft_print_test_string("MINE", str1, "STRING");
	ft_print_run_cmd("ft_memchr(str1, 'a', 400)");
	ft_print_result("STRING" ,ft_memchr(str1, 'a', 400));

	ft_reset_strings(str1, str2, 1, 1);

	// FT_MEMCMP
	ft_print_func_name("FT_MEMCMP", BLUE);
	ft_print_test_strings("ORG", str1, str2, "STRING1", "STRING2");
	ft_print_run_cmd("memcmp(str1, str2, 26)");
	printf("  RETURN VALUE: %d\n\n", memcmp("abcdefghij", "abcdefgxyz", 8));

	ft_print_test_strings("MINE", str1, str2, "STRING1", "STRING2");
	ft_print_run_cmd("ft_memcmp(str1, str2, 26)");
	printf("  RETURN VALUE: %d\n\n", ft_memcmp("abcdefghij", "abcdefgxyz", 8));


	ft_reset_strings(str1, str2, 1, 1);

	// FT_STRLEN
	ft_print_func_name("FT_STRLEN", BLUE);
	printf("  Test string: %s\n", str1);
	printf("  MINE: %lu\n", ft_strlen(str1));
	printf("  ORG: %lu\n", strlen(str1));

	ft_reset_strings(str1, str2, 1, 1);

	// FT_STRDUP
	char	*dup;

	dup = NULL;
	ft_print_func_name("FT_STRDUP", BLUE);
	printf(" ORG\n");
	printf("  String to duplicate: %s\n", str1);
	printf("  Duplicated string address before strdup() %p\n", dup);
	dup = strdup(str1);
	printf("  Duplicated string address after strdup() %p\n", dup);
	printf("  Duplicated string LEN=%zu VALUE after strdup = '%s'\n", strlen(dup),dup);
	free(dup);

	printf(" MINE\n");
	printf("  String to duplicate: %s\n", str1);
	printf("  Duplicated string address before strdup() %p\n", dup);
	dup = ft_strdup(str1);
	printf("  Duplicated string address after strdup() %p\n", dup);
	printf("  Duplicated string LEN=%zu VALUE after strdup = '%s'\n", strlen(dup),dup);
	free(dup);

	ft_reset_strings(str1, str2, 1, 1);

	// FT_STRCPY
	ft_print_func_name("FT_STRCPY", BLUE);
	printf(" ORG\n");
	printf("  SRC: %s\n", str1+5);
	printf("  DST: %s\n", str2);
	printf("  running strcpy(DST, SRC) DSTSIZE = %lu SRCSIZE = %lu\n", strlen(str2), strlen(str1+5));
	strcpy(str2, str1+5);
	printf("  DST STRING: %s\n", str2);
	printf("  DST[23]: %c\n\n", str2[23]);

	ft_reset_strings(str1, str2, 1, 1);

	printf(" MINE\n");
	printf("  SRC: %s\n", str1+5);
	printf("  DST: %s\n", str2);
	printf("  running strcpy(DST, SRC) DSTSIZE %lu SRCSIZE %lu\n", strlen(str2), strlen(str1+5));
	ft_strcpy(str2, str1+5);
	printf("  DST STRING: %s\n", str2);
	printf("  DST[23]: %c\n", str2[23]);

	ft_reset_strings(str1, str2, 1, 2);

	// FT_STRNCPY
	ft_print_func_name("FT_STRNCPY", BLUE);
	printf(" ORG\n");
	printf("  SRC: %s\n", str1);
	printf("  DST: %s\n", str2);
	printf("  running strncpy(DST, SRC, 30)  DSTSIZE %lu SRCSIZE %lu\n", strlen(str2), strlen(str1));
	strncpy(str2, str1, 30);
	printf("  DST STRING: %s\n\n", str2);

	ft_reset_strings(str1, str2, 1, 2);

	printf(" MINE\n");
	printf("  SRC: %s\n", str1);
	printf("  DST: %s\n", str2);
	printf("  running strncpy(DST, SRC 30) DSTSIZE %lu SRCSIZE %lu\n", strlen(str2), strlen(str1));
	ft_strncpy(str2, str1, 30);
	printf("  DST STRING: %s\n\n", str2);

	ft_reset_strings(str1, str2, 1, 2);

	printf(" ORG\n");
	printf("  SRC: %s\n", str1);
	printf("  DST: %s\n", str2);
	printf("  running strncpy(DST, SRC, 14) DSTSIZE %lu SRCSIZE %lu\n", strlen(str2), strlen(str1));
	strncpy(str2, str1, 14);
	printf("  DST STRING: %s\n\n", str2);

	ft_reset_strings(str1, str2, 1, 2);

	printf(" MINE\n");
	printf("  SRC: %s\n", str1);
	printf("  DST: %s\n", str2);
	printf("  running strncpy(DST, SRC, 14) DSTSIZE %lu SRCSIZE %lu\n", strlen(str2), strlen(str1));
	ft_strncpy(str2, str1, 14);
	printf("  DST STRING: %s\n", str2);

	ft_reset_strings(str1, str2, 1, 1);

	// FT_STRCAT
	ft_print_func_name("FT_STRCAT", BLUE);
	ft_print_test_strings("ORG", str1, str2, "STR1", "STR2");
	ft_print_run_cmd("strncat(STR1, STR2)");
	strcat(str1, str2);
	ft_print_result("STR1", str1);

	ft_reset_strings(str1, str2, 1, 1);

	ft_print_test_strings("MINE", str1, str1, "STR1", "STR2");
	ft_print_run_cmd("strncat(STR1, STR2)");
	ft_strcat(str1, str2);
	ft_print_result("STR1", str1);

	ft_reset_strings(str1, str2, 1, 1);

	// FT_STRNCAT
	ft_print_func_name("FT_STRNCAT", BLUE);
	ft_print_test_strings("ORG", str1, str2, "STR1", "STR2");
	ft_print_run_cmd("strncat(STR1, STR2, 14)");
	strncat(str1, str2, 14);
	ft_print_result("STR1", str1);

	ft_reset_strings(str1, str2, 1, 1);

	ft_print_test_strings("MINE", str1, str2, "STR1", "STR2");
	ft_print_run_cmd("strncat(STR1, STR2, 14)");
	ft_strncat(str1, str2, 14);
	ft_print_result("STR1", str1);

	ft_reset_strings(str1, str2, 1, 1);

	// FT_STRLCAT
	ft_print_func_name("FT_STRLCAT", BLUE);
	ft_print_test_strings("ORG", str1, str2, "STR1", "STR2");
	ft_print_run_cmd("strlcat(STR1, STR2, 14)");
	printf("  RETURN %zu\n", strlcat(str1, str2, 52));
	ft_print_result("STR1", str1);

	ft_reset_strings(str1, str2, 1, 1);

	ft_print_test_strings("MINE", str1, str2, "STR1", "STR2");
	ft_print_run_cmd("strlcat(STR1, STR2, 14)");
	printf("  RETURN %zu\n", ft_strlcat(str1, str2, 52));
	ft_print_result("STR1", str1);

	ft_reset_strings(str1, str2, 1, 1);

	// FT_STRCHR
	ft_print_func_name("FT_STRCHR", BLUE);
	ft_print_test_string("ORG", str1, "STR1");
	ft_print_run_cmd("strchr(STR1, 'i')");
	ft_print_result("POINTER", strchr(str1, 'i'));

	ft_reset_strings(str1, str2, 1, 1);
	
	ft_print_test_string("ORG", str1, "STR1");
	ft_print_run_cmd("ft_strchr(STR1, 'i')");
	ft_print_result("POINTER", ft_strchr(str1, 'i'));

	ft_reset_strings(str1, str2, 1, 1);

	// FT_STRRCHR
	ft_print_func_name("FT_STRRCHR", BLUE);
	ft_print_test_string("ORG", str1, "STR1");
	ft_print_run_cmd("strrchr(STR1, 'i')");
	ft_print_result("POINTER", strrchr(str1, 'i'));

	ft_reset_strings(str1, str2, 1, 1);
	
	ft_print_test_string("ORG", str1, "STR1");
	ft_print_run_cmd("ft_strrchr(STR1, 'i')");
	ft_print_result("POINTER", ft_strrchr(str1, 'i'));

	ft_reset_strings(str1, str2, 2, 0);

	// FT_STRSTR
	ft_print_func_name("FT_STRSTR", BLUE);
	ft_print_test_strings("ORG", needle, str1, "NEEDLE", "HAYSTACK");
	ft_print_run_cmd("ft_strstr(HAYSTACK, NEEDLE)");
	ft_print_result("POINTER", strstr(str1, needle));

	ft_reset_strings(str1, str2, 2, 0);

	ft_print_test_strings("MINE", needle, str1, "NEEDLE", "HAYSTACK");
	ft_print_run_cmd("ft_strstr(HAYSTACK, NEEDLE)");
	ft_print_result("POINTER", ft_strstr(str1, needle));


	ft_reset_strings(str1, str2, 2, 0);

	// FT_STRNSTR
	ft_print_func_name("FT_STRNSTR", BLUE);
	ft_print_test_strings("ORG", needle, str1, "NEEDLE", "HAYSTACK");
	ft_print_run_cmd("strnstr(HAYSTACK, NEEDLE, 52)");
	ft_print_result("POINTER", strnstr(str1, needle, 52));
	ft_print_run_cmd("strnstr(HAYSTACK, NEEDLE, 51)");
	ft_print_result("POINTER", strnstr(str1, needle, 51));

	ft_reset_strings(str1, str2, 2, 0);

	ft_print_test_strings("MINE", needle, str1, "NEEDLE", "HAYSTACK");
	ft_print_run_cmd("ft_strnstr(HAYSTACK, NEEDLE, 52)");
	ft_print_result("POINTER", ft_strnstr(str1, needle, 52));
	ft_print_run_cmd("ft_strnstr(HAYSTACK, NEEDLE, 51)");
	ft_print_result("POINTER", ft_strnstr(str1, needle, 51));

	ft_reset_strings(str1, str2, 1, 1);

	// FT_STRCMP
	ft_print_func_name("FT_STRCMP", BLUE);
	printf(" ORG\n");
	ft_print_run_cmd("strcmp(\"abcd\", \"abcd\")");
	printf("  RESULT (INT): %d\n\n", strcmp("abcd", "abcd"));
	ft_print_run_cmd("strcmp(\"abcde\", \"abcd\")");
	printf("  RESULT (INT): %d\n\n", strcmp("abcde", "abcd"));
	ft_print_run_cmd("strcmp(\"abc\", \"abcd\")");
	printf("  RESULT (INT): %d\n\n", strcmp("abc", "abcd"));

	ft_reset_strings(str1, str2, 1, 1);

	printf(" MINE\n");
	ft_print_run_cmd("ft_strcmp(\"abcd\", \"abcd\")");
	printf("  RESULT (INT): %d\n\n", ft_strcmp("abcd", "abcd"));
	ft_print_run_cmd("ft_strcmp(\"abcde\", \"abcd\")");
	printf("  RESULT (INT): %d\n\n", ft_strcmp("abcde", "abcd"));
	ft_print_run_cmd("ft_strcmp(\"abc\", \"abcd\")");
	printf("  RESULT (INT): %d\n\n", ft_strcmp("abc", "abcd"));

	// FT_STRNCMP
	ft_print_func_name("FT_STRNCMP", BLUE);
	printf(" ORG\n");
	ft_print_run_cmd("strncmp(\"abcd\", \"abce\", 3)");
	printf("  RESULT (INT): %d\n\n", strncmp("abcd", "abce", 3));
	ft_print_run_cmd("strncmp(\"abc\", \"abcde\", 5)");
	printf("  RESULT (INT): %d\n\n", strncmp("abc", "abcde", 5));
	ft_print_run_cmd("strncmp(\"abcd\", \"abcd\", 6)");
	printf("  RESULT (INT): %d\n\n", strncmp("abcd", "abcd", 6));

	ft_reset_strings(str1, str2, 1, 1);

	printf(" MINE\n");
	ft_print_run_cmd("ft_strncmp(\"abcd\", \"abce\", 3)");
	printf("  RESULT (INT): %d\n\n", ft_strncmp("abcd", "abce", 3));
	ft_print_run_cmd("ft_strncmp(\"abc\", \"abcde\", 5)");
	printf("  RESULT (INT): %d\n\n", ft_strncmp("abc", "abcde", 5));
	ft_print_run_cmd("ft_strncmp(\"abcd\", \"abcd\", 6)");
	printf("  RESULT (INT): %d\n\n", ft_strncmp("abcd", "abcd", 6));

	ft_reset_strings(str1, str2, 1, 1);

	// FT_ATOI
	ft_print_func_name("FT_ATOI", BLUE);
	printf(" ORG\n");
	ft_print_run_cmd("atoi(\"1234\")");
	printf("  RESULT (INT): %d\n", atoi("1234"));

	printf(" MINE\n");
	ft_print_run_cmd("atoi(\"1234\")");
	printf("  RESULT (INT): %d\n", ft_atoi("1234"));

	// FT_ISALPHA	
	ft_print_func_name("FT_ISALPHA", BLUE);
	printf("isalpha('a') RESULT ORG %d | MINE %d\n", isalpha('a'), ft_isalpha('a'));
	printf("isalpha('3') RESULT ORG %d | MINE %d\n", isalpha('3'), ft_isalpha('3'));
	printf("isalpha(132) RESULT ORG %d | MINE %d\n", isalpha(132), ft_isalpha(132));

	// FT_ISDIGIT
	ft_print_func_name("FT_DIGIT", BLUE);
	printf("isdigit('a') RESULT ORG %d | MINE %d\n", isdigit('a'), ft_isdigit('a'));
	printf("isdigit('3') RESULT ORG %d | MINE %d\n", isdigit('3'), ft_isdigit('3'));

	// FT_ISALNUM
	ft_print_func_name("FT_ISALNUM", BLUE);
	printf("isalnum('a') RESULT ORG %d | MINE %d\n", isalnum('a'), ft_isalnum('a'));
	printf("isalnum('3') RESULT ORG %d | MINE %d\n", isalnum('3'), ft_isalnum('3'));
	printf("isalnum('^') RESULT ORG %d | MINE %d\n", isalnum('^'), ft_isalnum('^'));

	// FT_ISASCII
	ft_print_func_name("FT_ISASCII", BLUE);
	printf("isascii(0) RESULT ORG %d | MINE %d\n", isascii(0), ft_isascii(0));
	printf("isascii(127) RESULT ORG %d | MINE %d\n", isascii(127), ft_isascii(127));
	printf("isascii(128) RESULT ORG %d | MINE %d\n", isascii(128), ft_isascii(128));

	// FT_ISPRINT
	ft_print_func_name("FT_ISPRINT", BLUE);
	printf("isprint(1) RESULT ORG %d | MINE %d\n", isprint(1), ft_isprint(1));
	printf("isprint(48) RESULT ORG %d | MINE %d\n", isprint(48), ft_isprint(48));
	printf("isprint(127) RESULT ORG %d | MINE %d\n", isprint(127), ft_isprint(127));

	// FT_TOUPPER
	ft_print_func_name("FT_TOUPPER", BLUE);
	printf("toupper('a') RESULT ORG %c | MINE %c\n", toupper('a'), ft_toupper('a'));
	printf("toupper('z') RESULT ORG %c | MINE %c\n", toupper('z'), ft_toupper('z'));
	printf("toupper('^') RESULT ORG %c | MINE %c\n", toupper('^'), ft_toupper('^'));
	printf("toupper('A') RESULT ORG %c | MINE %c\n", toupper('A'), ft_toupper('A'));


	// FT_TOLOWER
	ft_print_func_name("FT_TOLOWER", BLUE);
	printf("tolower('A') RESULT ORG %c | MINE %c\n", tolower('A'), ft_tolower('A'));
	printf("tolower('Z') RESULT ORG %c | MINE %c\n", tolower('Z'), ft_tolower('Z'));
	printf("tolower('^') RESULT ORG %c | MINE %c\n", tolower('^'), ft_tolower('^'));
	printf("tolower('a') RESULT ORG %c | MINE %c\n", tolower('a'), ft_tolower('a'));

	ft_print_header("PART 2 - ADDITIONAL FUNCTIONS", GREEN);

	// FT_MEMALLOC
	ft_print_func_name("FT_MEMALLOC", BLUE);
	v_ptr = ft_memalloc(sizeof(char) * 6);
	printf("    RUNNING TEST SILENTLY, ABORTS ON FAIL\n");
	ft_test_mem(v_ptr, 6, 0, 525);
	free(v_ptr);

	// FT_MEMDEL
	ft_print_func_name("FT_MEMDEL", BLUE);
	c_ptr = ft_strdup("Test string!");
	ft_print_test_string("MINE", c_ptr, "CHAR_PTR");
	ft_print_run_cmd("ft_memdel(&PTR)");
	ft_memdel((void*)&c_ptr);
	ft_print_result("CHAR_PTR", c_ptr);

	// FT_STRNEW
	ft_print_func_name("FT_STRNEW", BLUE);
	ft_print_run_cmd("(c_ptr = ft_strnew(4)");
	c_ptr = ft_strnew(4);
	ft_print_run_cmd("ft_strcpy(PTR, \"abcd\")");
	ft_strcpy(c_ptr, "abcd");
	ft_print_result("CHAR_PTR", c_ptr);
	ft_memdel((void*)&c_ptr);

	// FT_STRDEL
	ft_print_func_name("FT_STRDEL", BLUE);
	c_ptr = ft_strdup("Test string!");
	ft_print_test_string("MINE", c_ptr, "CHAR_PTR");
	ft_print_run_cmd("ft_memdel(&PTR)");
	ft_strdel(&c_ptr);
	ft_print_result("CHAR_PTR", c_ptr);


	// FT_STRCLR
	ft_print_func_name("FT_STRCLR", BLUE);
	ft_print_test_string("MINE", str1, "STRING");
	ft_print_run_cmd("ft_strclr(STRING)");
	ft_strclr(str1);
	ft_print_result("STRING", str1);
	ft_print_result("&STRING[25]", &str1[25]);

	ft_reset_strings(str1, str2, 1, 1);

	
	// FT_STRITER
	ft_print_func_name("FT_STRITER", BLUE);
	ft_print_test_string("MINE", str1, "STRING");
	ft_print_run_cmd("ft_striter(&STRING[23], &ft_putstr)");

	ft_striter(&str1[23], &ft_putstr);
	printf("\n");
	ft_reset_strings(str1, str2, 1, 1);

	// FT_STRITERI
	ft_print_func_name("FT_STRITERI", BLUE);
	ft_print_test_string("MINE", str1, "STRING");
	ft_print_run_cmd("ft_striteri(&STRING[23], &ft_print_ci)");
	ft_striteri(&str1[23], &ft_print_ci);

	ft_reset_strings(str1, str2, 1, 1);

	// FT_STRMAP
	ft_print_func_name("FT_STRMAP", BLUE);
	ft_print_test_string("MINE", "TEST STRING", "STRING");
	ft_print_run_cmd("c_ptr = ft_strmap(STRING, &ft_tolower)");
	c_ptr = ft_strmap("TEST STRING", &ft_tolower);
	ft_print_result("STRING", c_ptr);

	ft_memdel((void*)&c_ptr);
	//ft_print_result("HAH", c_ptr);
	// FT_STRMAPI
	ft_print_func_name("FT_STRMAPI", BLUE);
	ft_print_test_string("MINE", "TEST STRING", "STRING");
	ft_print_run_cmd("c_ptr = ft_strmapi(STRING, &ft_print_strmapi_test)");
	c_ptr = ft_strmapi("TEST STRING", &ft_print_strmapi_test);
	ft_print_result("STRING", c_ptr);

	ft_memdel((void*)&c_ptr);

	// FT_STREQU
	ft_print_func_name("FT_STREQU", BLUE);
	ft_print_run_cmd("ft_strequ(\"IDENTICAL\", \"IDENTICAL\")");
	printf("%s  RESULT: %d%s\n\n", GREEN, ft_strequ("IDENTICAL", "IDENTICAL"), RESET);
	ft_print_run_cmd("ft_strequ(\"UN1DENTICAL\", \"UNIDENTICAL\")");
	printf("%s  RESULT: %d%s\n", GREEN, ft_strequ("UN1DENTICAL", "UNIDENTICAL"), RESET);

	// FT_STRNEQU
	ft_print_func_name("FT_STRNEQU", BLUE);
	ft_print_run_cmd("ft_strnequ(\"UN1DENTICAL\", \"UNIDENTICAL\", 2)");
	printf("%s  RESULT: %d%s\n\n", GREEN, ft_strnequ("UN1DENTICAL", "UNIDENTICAL", 2), RESET);
	ft_print_run_cmd("ft_strnequ(\"UN1DENTICAL\", \"UNIDENTICAL\", 5)");
	printf("%s  RESULT: %d%s\n", GREEN, ft_strnequ("UN1DENTICAL", "UNIDENTICAL", 5), RESET);

	// FT_STRSUB
	ft_print_func_name("FT_STRSUB", BLUE);
	ft_print_run_cmd("ft_strsub(\"TEST STRING\", 5, 6)");
	printf("%s  RESULT: '%s'%s\n", GREEN, ft_strsub("TEST STRING", 5, 6), RESET);

	// FT_STRJOIN
	ft_print_func_name("FT_STRJOIN", BLUE);
	ft_print_run_cmd("ft_strjoin(\"String one.\",\"String two.\")");
	printf("%s  RESULT: '%s'%s\n", GREEN, ft_strjoin("String one.", "String two."), RESET);

	// FT_STRTRIM
	ft_print_func_name("FT_STRTRIM", BLUE);
	ft_print_run_cmd("ft_strtrim(\"\\t\\n test string \\t\\n\")");
	printf("%s  RESULT: '%s'%s\n\n", GREEN, ft_strtrim("\t\n test string \t\n"), RESET);
	ft_print_run_cmd("ft_strtrim(\"\")");
	printf("%s  RESULT: '%s'%s\n\n", GREEN, ft_strtrim(""), RESET);
	ft_print_run_cmd("ft_strtrim(NULL)");
	printf("%s  RESULT: '%s'%s\n", GREEN, ft_strtrim(NULL), RESET);

	// FT_STRSPLIT
	ft_print_func_name("FT_STRSPLIT", BLUE);
	char	**str_arr;
	ft_print_run_cmd("str_arr = ft_strsplit(\"This is a funky sentence!\", ' ')");

	str_arr = ft_strsplit("This is a funky sentence!", ' ');
	i = 0;
	while (str_arr[i])
	{
		printf("%s INDEX: %zu VALUE: '%s'%s\n", GREEN, i, str_arr[i], RESET);
		i++;
	}
	// FT_ITOA
	ft_print_func_name("FT_ITOA", BLUE);
	ft_print_run_cmd("ft_itoa(-2147483648)");
	ft_print_result("STRING", ft_itoa(-2147483648));
	ft_print_run_cmd("ft_itoa(2147483647)");
	ft_print_result("STRING", ft_itoa(2147483647));
	ft_print_run_cmd("ft_itoa(1337)");
	ft_print_result("STRING", ft_itoa(1337));
	ft_print_run_cmd("ft_itoa(5430040)");
	ft_print_result("STRING", ft_itoa(5430040));


	// FT_PUTCHAR
	ft_print_func_name("FT_PUTCHAR", BLUE);
	ft_print_run_cmd("ft_putchar('a')");
	ft_putchar('a');

	// FT_PUTSTR
	ft_print_func_name("FT_PUTSTR", BLUE);
	ft_print_run_cmd("ft_putstr(\"abcdefg\")");
	ft_putstr("abcdefg");

	// FT_PUTENDL
	ft_print_func_name("FT_PUTENDL", BLUE);
	ft_print_run_cmd("ft_putstr(\"abcdefg\")");
	ft_putendl("Does this sentence end with new line?");

	// FT_PUTNBR
	ft_print_func_name("FT_PUTNBR", BLUE);
	ft_print_run_cmd("ft_putnbr(-2147483648)");
	ft_putnbr(-2147483648);
	printf("\n\n");
	ft_print_run_cmd("ft_putnbr(2147483647)");
	ft_putnbr(2147483647);

	printf("\n\n%s ---- CREATING TESTFILE ----\n READ OUTPUT FROM THE FILE ITSELF %s\n", RED, RESET);

	int	fd;
	if ((fd = open("TESTFILE", O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR)) < 0)
			printf("%d\n", fd);
	

	// FT_PUTCHAR_FD
	ft_print_func_name("FT_PUTCHAR_FD", BLUE);
	ft_print_run_cmd("ft_putchar_fd('a', fd)");
	ft_putchar_fd('a', fd);

	// FT_PUTSTR_FD
	ft_print_func_name("FT_PUTSTR_FD", BLUE);
	ft_print_run_cmd("ft_putstr_fd('bb', fd)");
	ft_putstr_fd("bb", fd);

	// FT_PUTENDL_FD
	ft_print_func_name("FT_PUTENDL", BLUE);
	ft_print_run_cmd("ft_putendl_fd('ccc', fd)");
	ft_putendl_fd("ccc", fd);

	// FT_PUTNBR_FD
	ft_print_func_name("FT_PUTNBR_FD", BLUE);
	ft_print_run_cmd("ft_putstr(123, fd)");
	ft_putnbr_fd(123, fd);


	ft_print_header("PART 3 - BONUS PART", YELLOW);

	// FT_LSTNEW
	ft_print_func_name("FT_LSTNEW", BLUE);
	ft_print_run_cmd("lst = ft_lstnew(ft_strdup(NULL, 5)");
	lst = ft_lstnew(NULL, 5);
	ft_print_result("CONTENT" ,lst->content);
	printf("%s  RESULT (CONTENT_SIZE): %zu%s\n\n", GREEN, lst->content_size, RESET);

	ft_print_run_cmd("lst = ft_lstnew(ft_strdup(\"This is a test string\"), sizeof(\"This is a test string\")");

	free(lst);
	lst = ft_lstnew(ft_strdup("This is a test string"), sizeof("This is a test string"));
	ft_print_result("CONTENT" ,lst->content);
	printf("%s  RESULT (CONTENT_SIZE): %zu%s\n", GREEN, lst->content_size, RESET);

	// FT_LSTDEL
	ft_print_func_name("FT_LSTDEL", BLUE);
	lst = ft_init_list();
	ft_print_list(lst);
	ft_print_run_cmd("lst = ft_lstdel(LST, &ft_del)");
	ft_lstdel(&lst, &ft_del);
	printf("POINTER TO LST: '%p' \n", lst);

	// FT_LSTDELONE
	//lst = ft_lstnew(ft_strdup("This is a test string"), sizeof("This is a test string"));
	ft_print_func_name("FT_LSTDELONE", BLUE);
	ft_lstdelone(&lst, &ft_del);
	printf("ADDRESS OF POINTER TO LST: '%p' \n", lst);

	// FT_LSTADD
	ft_print_func_name("FT_LSTADD", BLUE);
	t_list	*new_lst;
	new_lst = ft_lstnew(ft_strdup("This is a test string"), sizeof("This is a test string"));
	lst = ft_init_list();
	printf("STRING TO ADD' %s'%s'%s\n\n", YELLOW, "This is a test string", RESET);

	ft_print_list(lst);
	ft_print_run_cmd("ft_lstadd(&LST, NEWSTRING)");
	ft_lstadd(&lst, new_lst);
	ft_print_list(lst);

	// FT_LSTITER
	ft_lstdel(&lst, &ft_del);
	ft_print_func_name("FT_LSTITER", BLUE);
	lst = ft_init_list();
	ft_print_run_cmd("ft_lstiter(lst, &ft_test_lstiter)");
	ft_lstiter(lst, &ft_test_lstiter);

	// FT_LSTMAP
	ft_print_func_name("FT_LSTMAP", BLUE);
	ft_lstdel(&lst, &ft_del);
	lst = ft_init_list();
	ft_print_run_cmd("ft_lstmap(lst, &ft_test_lstmap)");
	ft_print_list(ft_lstmap(lst, &ft_test_lstmap));
	

	ft_print_header("PART 4 - ADdITIONAL FUNCTIONS", RED);

	// FT_LSTADDEND
	ft_print_func_name("FT_LSTADDEND", BLUE);
	ft_lstdel(&lst, &ft_del);
	

	new_lst = ft_lstnew(ft_strdup("This is a test string!"), sizeof("This is a test string!"));
	lst = ft_init_list();
	printf("\n  NEW STRING '%s'%s'%s\n\n", YELLOW, new_lst->content, RESET);

	ft_print_list(lst);
	ft_print_run_cmd("ft_lstaddend(&LST, NEWSTRING)");
	ft_lstaddend(&lst, new_lst);
	ft_print_list(lst);

	// FT_ISLOWER
	ft_print_func_name("FT_ISLOWER", BLUE);
	printf("islower('5') RESULT  %d\n", ft_islower('5'));
	printf("islower('b') RESULT  %d\n", ft_islower('b'));
	printf("islower('B') RESULT  %d\n", ft_islower('B'));
	printf("islower(NULL) RESULT  %d\n", ft_islower(NULL));


	// FT_ISUPPER
	ft_print_func_name("FT_ISUPPER", BLUE);
	printf("isupper('5') RESULT  %d\n", ft_isupper('5'));
	printf("isupper('b') RESULT  %d\n", ft_isupper('b'));
	printf("isupper('B') RESULT  %d\n", ft_isupper('B'));
	printf("isupper(NULL) RESULT  %d\n", ft_isupper(NULL));

	// FT_STRNDUP
	ft_reset_strings(str1, str2, 1, 1);
	ft_print_func_name("FT_STRNDUP", BLUE);
	ft_print_test_string("ORG", str1, "STRING");
	ft_print_run_cmd("strndup(STR, 20)");
	ft_print_result("ORG STRING" ,strndup(str1, 20));
	printf("%s  ORG STRING LEN %zu%s\n\n" , GREEN, ft_strlen(strndup(str1, 20)), RESET);
	ft_print_run_cmd("ft_strndup(STR, 20)");
	ft_print_result("MINE STRING" ,ft_strndup(str1, 20));
	printf("%s  MINE STRING LEN %zu%s\n" , GREEN, ft_strlen(strndup(str1, 20)), RESET);

	// FT_SWAP
	char st1[] = "STRING 1";
	char st2[] = "STRING 2";
	ft_print_func_name("FT_SWAP", BLUE);
	printf("STR1 = %s | STR2 = %s BEFORE SWAP\n\n", st1, st2);
	ft_print_run_cmd("ft_swap((void*)&STR1, (void*)&STR2)");
	ft_swap((void*)&st1, (void*)&st2);
	printf("STR1 = %s | STR2 = %s AFTER SWAP\n\n", st1, st2);

	printf("\n---- TESTS END----\n");

	return (0);
}
