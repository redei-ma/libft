#include "test.h"
#include <ctype.h>

void	test_type(void)
{
	printf("type\n");
	check_bool("ft_isalpha on 'a'", ft_isalpha('a'), isalpha('a'));
	check_bool("ft_isalpha on '7'", ft_isalpha('7'), isalpha('7'));
	check_bool("ft_isdigit on '7'", ft_isdigit('7'), isdigit('7'));
	check_bool("ft_isalnum on '_'", ft_isalnum('_'), isalnum('_'));
	check_bool("ft_isascii on 200", ft_isascii(200), isascii(200));
	check_bool("ft_isascii on 65", ft_isascii(65), isascii(65));
	check_bool("ft_isprint on newline", ft_isprint('\n'), isprint('\n'));
	check_bool("ft_isspace on tab", ft_isspace('\t'), isspace('\t'));
	check_bool("ft_isspace on 'a'", ft_isspace('a'), isspace('a'));
	check_int("ft_toupper", ft_toupper('a'), toupper('a'));
	check_int("ft_tolower", ft_tolower('A'), tolower('A'));
	check_int("ft_abs positive", ft_abs(5), 5);
	check_int("ft_abs negative", ft_abs(-5), 5);
	check_int("ft_abs zero", ft_abs(0), 0);
	check_int("ft_atoi spaces", ft_atoi("  42"), atoi("  42"));
	check_int("ft_atoi trailing", ft_atoi("15d7"), atoi("15d7"));
	check_int("ft_atoi sign", ft_atoi("-42"), atoi("-42"));
	check_int("ft_natoi rejects spaces", ft_natoi("  42"), 0);
	check_int("ft_natoi rejects trailing", ft_natoi("15d7"), 0);
	check_int("ft_natoi rejects overflow", ft_natoi("2147483648"), 0);
	check_int("ft_natoi valid", ft_natoi("-42"), -42);
}
