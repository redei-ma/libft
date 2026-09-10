#include "test.h"

void	test_mem(void)
{
	char	a[20] = "destination";
	char	b[20] = "destination";
	char	over[20] = "0123456789";

	printf("mem\n");
	ft_memcpy(a, "source", 6);
	memcpy(b, "source", 6);
	check_str("ft_memcpy", a, b);
	ft_memset(a, 'x', 3);
	memset(b, 'x', 3);
	check_str("ft_memset", a, b);
	ft_bzero(a, 4);
	check_int("ft_bzero first byte", a[0], 0);
	check_int("ft_bzero fourth byte", a[3], 0);
	check_sign("ft_memcmp when a < b", ft_memcmp("abc", "abd", 3), -1);
	check_sign("ft_memcmp on equal", ft_memcmp("abc", "abc", 3), 0);
	check_str("ft_memchr", ft_memchr("goodmorning", 'm', 11), memchr("goodmorning", 'm', 11));
	check_str("ft_memchr missing", ft_memchr("hello", 'z', 5), memchr("hello", 'z', 5));
	ft_memmove(over + 2, over, 5);
	check_str("ft_memmove overlapping", over, "0101234789");
}
