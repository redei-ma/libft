#include "test.h"

/*
Only the functions written for this library are checked here. The ones that
mirror the C library are left out on purpose: strlen(NULL) is undefined
behaviour in the original too, and ft_strlen matches it. Testing a crash would
mean testing undefined behaviour.
*/
void	test_null(void)
{
	void	*grown;

	printf("null input\n");
	check_int("ft_natoi", ft_natoi(NULL), 0);
	check_str("ft_substr", ft_substr(NULL, 0, 3), NULL);
	check_str("ft_strjoin first null", ft_strjoin(NULL, "a"), NULL);
	check_str("ft_strjoin second null", ft_strjoin("a", NULL), NULL);
	check_str("ft_strtrim", ft_strtrim(NULL, " "), NULL);
	check_int("ft_split", ft_split(NULL, ' ') == NULL, 1);
	check_int("ft_nsplit", ft_nsplit(NULL) == NULL, 1);
	check_int("ft_matlen", ft_matlen(NULL), 0);
	check_int("ft_free_mat", ft_free_mat(NULL, 3) == NULL, 1);
	check_int("ft_free_char_mat", ft_free_char_mat(NULL) == NULL, 1);
	grown = ft_realloc(NULL, 0, 8);
	check_int("ft_realloc", grown != NULL, 1);
	free(grown);
	check_int("ft_lstsize", ft_lstsize(NULL), 0);
	check_int("ft_lstlast", ft_lstlast(NULL) == NULL, 1);
	check_int("ft_lstmap", ft_lstmap(NULL, NULL, NULL) == NULL, 1);
	ft_lstiter(NULL, NULL);
	ft_lstclear(NULL, NULL);
	ft_lstdelone(NULL, NULL);
	check_int("the void ft_lst* on null", 1, 1);
	ft_putstr_fd(NULL, 1);
	ft_putendl_fd(NULL, 1);
	check_int("ft_putstr_fd, ft_putendl_fd", 1, 1);
	safe_close(NULL);
	check_int("safe_close", 1, 1);
}
