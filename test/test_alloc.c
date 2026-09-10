#include "test.h"

void	test_alloc(void)
{
	char	*s;
	char	**parts;
	int		n;

	printf("alloc\n");
	s = ft_substr("Hello folks how are you???", 12, 11);
	check_str("ft_substr", s, "how are you");
	free(s);
	s = ft_substr("ciao", 100, 5);
	check_str("ft_substr past end", s, "");
	free(s);
	s = ft_itoa(-2147483648);
	check_str("ft_itoa INT_MIN", s, "-2147483648");
	free(s);
	s = ft_itoa(0);
	check_str("ft_itoa zero", s, "0");
	free(s);
	s = ft_strdup("hello world");
	check_str("ft_strdup", s, "hello world");
	free(s);
	s = ft_strjoin("Hello wor", "ld");
	check_str("ft_strjoin", s, "Hello world");
	free(s);
	s = ft_strtrim("  \t hello \n ", " \t\n");
	check_str("ft_strtrim", s, "hello");
	free(s);
	s = ft_strtrim("aaa", "a");
	check_str("ft_strtrim all trimmed", s, "");
	free(s);
	parts = ft_split("  a   b  ", ' ');
	n = ft_matlen(parts);
	check_int("ft_split repeated seps", n, 2);
	check_str("ft_split first", parts[0], "a");
	ft_free_char_mat(parts);
	parts = ft_nsplit("one two\tthree");
	check_int("ft_nsplit on blanks", ft_matlen(parts), 3);
	check_str("ft_nsplit third", parts[2], "three");
	ft_free_char_mat(parts);
	s = ft_calloc(4, sizeof(char));
	check_int("ft_calloc zeroes", s[0] == 0 && s[3] == 0, 1);
	s = ft_realloc(s, 4, 16);
	ft_strlcpy(s, "grown", 6);
	check_str("ft_realloc keeps writing", s, "grown");
	free(s);
	check_int("ft_calloc overflow guard", ft_calloc((size_t)-1, 2) == NULL, 1);
}
