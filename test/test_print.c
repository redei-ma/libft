#include "test.h"
#include <unistd.h>
#include <fcntl.h>

void	test_print(void)
{
	char	*out;
	int		n;
	int		fd;

	printf("print\n");
	capture_start(1);
	n = ft_printf("%s %d %c %x", "text", -42, 'z', 255);
	out = capture_end(1);
	check_str("ft_printf output", out, "text -42 z ff");
	check_int("ft_printf return", n, 13);
	free(out);

	capture_start(1);
	n = ft_printf("%d%%", 7);
	out = capture_end(1);
	check_str("ft_printf percent", out, "7%");
	free(out);

	capture_start(1);
	ft_putchar('A');
	ft_putstr("BC");
	ft_putnbr(-9);
	ft_puthex(255, 'x');
	out = capture_end(1);
	check_str("ft_putchar and friends", out, "ABC-9ff");
	free(out);

	capture_start(1);
	ft_putchar_fd('A', 1);
	ft_putstr_fd("BC", 1);
	ft_putnbr_fd(-9, 1);
	ft_putendl_fd("!", 1);
	out = capture_end(1);
	check_str("the *_fd family", out, "ABC-9!\n");
	free(out);

	fd = open("/tmp/libft_fprintf", O_CREAT | O_TRUNC | O_WRONLY, 0644);
	n = ft_fprintf(fd, "%s=%d", "answer", 42);
	close(fd);
	check_int("ft_fprintf return", n, 9);
	fd = open("/tmp/libft_fprintf", O_RDONLY);
	out = malloc(64);
	n = read(fd, out, 63);
	close(fd);
	out[n > 0 ? n : 0] = '\0';
	check_str("ft_fprintf wrote to fd", out, "answer=42");
	free(out);

	capture_start(1);
	ft_putchard('A', 1);
	ft_putstrd("BC", 1);
	ft_putnbrd(-9, 1);
	ft_puthexd(255, 'x', 1);
	out = capture_end(1);
	check_str("the *d family", out, "ABC-9ff");
	free(out);
}
