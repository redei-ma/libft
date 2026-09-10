# libft

A C standard library written from scratch, with no dependency beyond `malloc`,
`free`, `write` and `read`. It holds three 42 projects that in practice form a
single library — **libft**, **ft_printf** and **get_next_line** — because they
compile into one `libft.a` and every other project links them together.

66 functions, 1.9k lines, and a test suite that covers all of them.

## What is inside

| Group | Functions |
|---|---|
| `type/` | `isalpha` `isdigit` `isalnum` `isascii` `isprint` `isspace` |
| `str/` | `strlen` `strchr` `strrchr` `strncmp` `strcmp` `strlcpy` `strlcat` `strnstr` `striteri` `strmapi` |
| `mem/` | `memset` `bzero` `memcpy` `memmove` `memchr` `memcmp` |
| `alloc/` | `calloc` `strdup` `substr` `strjoin` `strtrim` `split` `nsplit` `itoa` `realloc` |
| `lst/` | `lstnew` `lstadd_front` `lstadd_back` `lstsize` `lstlast` `lstdelone` `lstclear` `lstiter` `lstmap` |
| `print/` | `printf` `fprintf` `putchar_fd` `putstr_fd` `putendl_fd` `putnbr_fd` |
| root | `abs` `atoi` `natoi` `tolower` `toupper` `matlen` `free_mat` `free_char_mat` `safe_close` `get_next_line` |

Every name carries the `ft_` prefix, except `get_next_line` and `safe_close`.

## Build and use

```bash
make            # builds libft.a
make test       # builds it, then runs the test suite
make debug      # same as make, with -g
make fclean     # removes everything it produced
```

```bash
cc -I path/to/libft/include main.c path/to/libft/libft.a -o program
```

```c
#include "libft.h"        /* everything except the printf family */
#include "ft_printf.h"    /* ft_printf */
#include "ft_fprintf.h"   /* ft_fprintf, the same towards a file descriptor */
```

`make test` runs 109 cases and exits non-zero if any fails. Where the C library
has an equivalent the result is compared against it, `ft_memcpy` against
`memcpy` and so on; elsewhere against a written expectation.

## Repository layout

```
.
├── include/     libft.h, plus one header each for printf and fprintf
├── src/         one directory per group, one file per function
├── test/        one file per group, plus the comparators
├── Makefile
└── LICENSE
```

## Notes

`ft_atoi` behaves like the standard one, skipping leading whitespace and
stopping at the first non-digit. **`ft_natoi`** is the strict variant: it
returns 0 for anything that is not a clean number in the `int` range, including
leading spaces, trailing characters and overflow.

Only the bonus **get_next_line** is here, the one that keeps a buffer per file
descriptor and can therefore read several files at once. `BUFFER_SIZE` defaults
to 10 and can be overridden with `-D BUFFER_SIZE=n`.

Functions written for this library accept `NULL` and return a defined value.
Those that mirror the C library behave like the originals, so `ft_strlen(NULL)`
faults exactly as `strlen(NULL)` does.

`ft_free_char_mat` frees a `NULL`-terminated matrix of strings and returns
`NULL`, so it can be used as `mat = ft_free_char_mat(mat);`. Use `ft_free_mat`
for a matrix of anything else: it takes any `void **` but needs the element
count, having no terminator to rely on.
