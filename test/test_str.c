#include "test.h"

static void	to_upper_i(unsigned int i, char *c)
{
	(void)i;
	if (*c >= 'a' && *c <= 'z')
		*c -= 32;
}

static char	to_upper_m(unsigned int i, char c)
{
	(void)i;
	if (c >= 'a' && c <= 'z')
		c -= 32;
	return (c);
}

void	test_str(void)
{
	char	dst[50] = "destination";
	char	buf[50] = "abc";
	char	iter[20] = "hello world";
	char	*s;

	printf("str\n");
	check_int("ft_strlen", ft_strlen("hello wor\tld"), strlen("hello wor\tld"));
	check_int("ft_strlen empty", ft_strlen(""), 0);
	check_str("ft_strchr", ft_strchr("hello", 'l'), strchr("hello", 'l'));
	check_str("ft_strchr missing", ft_strchr("hello", 'z'), strchr("hello", 'z'));
	check_str("ft_strrchr", ft_strrchr("hello", 'l'), strrchr("hello", 'l'));
	check_sign("ft_strcmp on equal", ft_strcmp("abc", "abc"), 0);
	check_sign("ft_strcmp when a < b", ft_strcmp("abc", "abd"), -1);
	check_sign("ft_strncmp when a < b", ft_strncmp("abc", "abd", 3), -1);
	check_sign("ft_strncmp with n = 0", ft_strncmp("abc", "xyz", 0), 0);
	check_int("ft_strlcpy", ft_strlcpy(dst, "source text", 5), 11);
	check_str("ft_strlcpy truncates", dst, "sour");
	check_int("ft_strlcat short size", ft_strlcat(buf, "XYZ", 2), 5);
	check_str("ft_strnstr", ft_strnstr("hello world", "wor", 11), "world");
	check_str("ft_strnstr not found", ft_strnstr("hello", "zz", 5), NULL);
	check_str("ft_strnstr empty needle", ft_strnstr("hello", "", 5), "hello");
	ft_striteri(iter, to_upper_i);
	check_str("ft_striteri", iter, "HELLO WORLD");
	s = ft_strmapi("hello world", to_upper_m);
	check_str("ft_strmapi", s, "HELLO WORLD");
	free(s);
}
