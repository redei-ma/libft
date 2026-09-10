#include "test.h"
#include <unistd.h>
#include <fcntl.h>

static int	g_failed = 0;
static int	g_passed = 0;
static int	g_saved = -1;

void	check_int(const char *name, long got, long expected)
{
	if (got == expected)
	{
		printf("  ok   %-30s %ld\n", name, got);
		g_passed++;
	}
	else
	{
		printf("  FAIL %-30s got %ld, expected %ld\n", name, got, expected);
		g_failed++;
	}
}

/*
Renders a string on one line: a newline inside a value would otherwise break
the column layout, and an invisible character would be indistinguishable from
a missing one.
*/
static const char	*shown(const char *s)
{
	static char	buf[128];
	size_t		i;
	size_t		j;

	if (!s)
		return ("(null)");
	i = 0;
	j = 0;
	while (s[i] && j < sizeof(buf) - 3)
	{
		if (s[i] == '\n' || s[i] == '\t' || s[i] == '\r')
		{
			buf[j++] = '\\';
			buf[j++] = "ntr"[(s[i] == '\t') + 2 * (s[i] == '\r')];
		}
		else
			buf[j++] = s[i];
		i++;
	}
	buf[j] = '\0';
	return (buf);
}

void	check_str(const char *name, const char *got, const char *expected)
{
	if ((!got && !expected) || (got && expected && !strcmp(got, expected)))
	{
		printf("  ok   %-30s \"%s\"\n", name, shown(got));
		g_passed++;
	}
	else
	{
		printf("  FAIL %-30s got \"%s\", expected \"%s\"\n", name,
			shown(got), shown(expected));
		g_failed++;
	}
}

/*
strcmp and memcmp only promise the sign of what they return, not the value:
glibc may answer -3 where another libc answers -1. So the sign is what gets
compared, while the real value is printed, which keeps the output honest.
*/
void	check_sign(const char *name, int got, int expected_sign)
{
	int	sign;

	sign = (got > 0) - (got < 0);
	if (sign == expected_sign)
	{
		printf("  ok   %-30s %d\n", name, got);
		g_passed++;
	}
	else
	{
		printf("  FAIL %-30s got %d, expected sign %d\n", name, got, expected_sign);
		g_failed++;
	}
}

/*
The is* family may return any non-zero value for true: glibc returns 1024 for
isalpha. Comparing the values would fail on a correct function, so truth is
what gets compared, and true/false is what gets printed.
*/
void	check_bool(const char *name, int got, int expected)
{
	if (!got == !expected)
	{
		printf("  ok   %-30s %s\n", name, got ? "true" : "false");
		g_passed++;
	}
	else
	{
		printf("  FAIL %-30s got %s, expected %s\n", name,
			got ? "true" : "false", expected ? "true" : "false");
		g_failed++;
	}
}

int	failures(void)
{
	return (g_failed);
}

int	passes(void)
{
	return (g_passed);
}

/*
Sends everything written to fd into a temp file, so a function that prints
can be checked on what it produced. capture_end puts fd back and returns the
text, which the caller frees.
*/
void	capture_start(int fd)
{
	int	tmp;

	fflush(stdout);
	g_saved = dup(fd);
	tmp = open("/tmp/libft_capture", O_CREAT | O_TRUNC | O_RDWR, 0644);
	dup2(tmp, fd);
	close(tmp);
}

char	*capture_end(int fd)
{
	char	*out;
	int		in;
	ssize_t	n;

	fflush(stdout);
	dup2(g_saved, fd);
	close(g_saved);
	out = malloc(4096);
	if (!out)
		return (NULL);
	in = open("/tmp/libft_capture", O_RDONLY);
	n = read(in, out, 4095);
	close(in);
	if (n < 0)
		n = 0;
	out[n] = '\0';
	return (out);
}
