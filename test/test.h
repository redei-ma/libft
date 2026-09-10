#ifndef TEST_H
# define TEST_H

# include "libft.h"
# include "ft_printf.h"
# include "ft_fprintf.h"
# include <stdio.h>
# include <string.h>
# include <stdlib.h>

/* one entry per group, called by main */
void	test_type(void);
void	test_str(void);
void	test_mem(void);
void	test_alloc(void);
void	test_lst(void);
void	test_print(void);
void	test_misc(void);
void	test_null(void);

/* reports one case: name, what libft gave, what the reference gave */
void	check_int(const char *name, long got, long expected);
void	check_str(const char *name, const char *got, const char *expected);

/* for functions that only guarantee the sign of their result, like strcmp */
void	check_sign(const char *name, int got, int expected_sign);

/* prints true/false instead of 1/0, for predicates like the is* family */
void	check_bool(const char *name, int got, int expected);

int		failures(void);
int		passes(void);

/* redirects a file descriptor to a temp file, to test what a function writes */
void	capture_start(int fd);
char	*capture_end(int fd);

#endif
