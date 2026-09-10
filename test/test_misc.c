#include "test.h"
#include <unistd.h>
#include <fcntl.h>

void	test_misc(void)
{
	void	**mat;
	char	**cmat;
	char	**empty;
	char	*line;
	int		fd;
	int		n;

	printf("misc\n");
	cmat = ft_split("a b c", ' ');
	check_int("ft_matlen", ft_matlen(cmat), 3);
	empty = ft_split("", 32);
	check_int("ft_matlen on empty", ft_matlen(empty), 0);
	ft_free_char_mat(empty);
	check_int("ft_free_char_mat returns null", ft_free_char_mat(cmat) == NULL, 1);

	mat = malloc(3 * sizeof(void *));
	mat[0] = ft_strdup("x");
	mat[1] = ft_strdup("y");
	mat[2] = NULL;
	check_int("ft_free_mat returns null", ft_free_mat(mat, 2) == NULL, 1);

	fd = open("/tmp/libft_gnl", O_CREAT | O_TRUNC | O_WRONLY, 0644);
	write(fd, "one\ntwo\nno newline", 18);
	close(fd);
	fd = open("/tmp/libft_gnl", O_RDONLY);
	line = get_next_line(fd);
	check_str("get_next_line first", line, "one\n");
	free(line);
	line = get_next_line(fd);
	check_str("get_next_line second", line, "two\n");
	free(line);
	line = get_next_line(fd);
	check_str("get_next_line last line", line, "no newline");
	free(line);
	line = get_next_line(fd);
	check_int("get_next_line at eof", line == NULL, 1);
	safe_close(&fd);
	check_int("safe_close sets fd to -1", fd, -1);
	n = -1;
	safe_close(&n);
	check_int("safe_close on -1 is a no-op", n, -1);
	check_int("get_next_line on bad fd", get_next_line(-1) == NULL, 1);
}
