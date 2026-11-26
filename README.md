_This project has been created as part of the 42 curriculum by marriche._

# Libft

## Description

**Libft** is the first project of the 42 curriculum. The goal is to build your own C static library, `libft.a`, by reimplementing a set of standard C library (libc) functions and adding a collection of general-purpose utility functions, including a small linked-list API.

The library is meant to be reused in later 42 projects. Writing these functions from scratch helps to understand how they work internally: memory handling, string manipulation, dynamic allocation, pointers, function pointers, and linked lists.

Constraints respected by the project:

- Written in C, following the 42 Norm.
- Compiled with `cc -Wall -Wextra -Werror`.
- No global variables.
- Library created with `ar` (no `libtool`).
- Helper functions are declared `static`.
- No memory leaks, no unexpected crashes.

## Instructions

### Compilation

```bash
make        # builds libft.a at the root of the repository
make clean  # removes object files
make fclean # removes object files and libft.a
make re     # fclean + all
```

The Makefile provides the rules `$(NAME)`, `all`, `clean`, `fclean` and `re`, and does not relink unnecessarily.

### Usage

Include the header in your code:

```c
#include "libft.h"
```

Then compile your program and link it against the library:

```bash
cc -Wall -Wextra -Werror main.c -L. -lft -o my_program
```

## Library description

All functions are declared in `libft.h`. The library is divided into three parts.

### Part 1 – Libc functions

Reimplementations of standard functions, with the same behavior as in the man pages and an `ft_` prefix.

| Category                                     | Functions                                                                                                 |
| -------------------------------------------- | --------------------------------------------------------------------------------------------------------- |
| Character classification (return `1` or `0`) | `ft_isalpha`, `ft_isdigit`, `ft_isalnum`, `ft_isascii`, `ft_isprint`                                      |
| Character conversion                         | `ft_toupper`, `ft_tolower`                                                                                |
| Strings                                      | `ft_strlen`, `ft_strlcpy`, `ft_strlcat`, `ft_strchr`, `ft_strrchr`, `ft_strncmp`, `ft_strnstr`, `ft_atoi` |
| Memory                                       | `ft_memset`, `ft_bzero`, `ft_memcpy`, `ft_memmove`, `ft_memchr`, `ft_memcmp`                              |
| Allocation (use `malloc`)                    | `ft_calloc`, `ft_strdup`                                                                                  |

### Part 2 – Additional functions

Functions that are not in the libc or exist in a different form.

| Function        | Description                                                                                     |
| --------------- | ----------------------------------------------------------------------------------------------- |
| `ft_substr`     | Returns a new substring of `s`, starting at index `start`, of maximum length `len`.             |
| `ft_strjoin`    | Returns a new string resulting from the concatenation of `s1` and `s2`.                         |
| `ft_strtrim`    | Returns a copy of `s1` with the characters from `set` removed from the beginning and the end.   |
| `ft_split`      | Splits `s` using the delimiter `c`; returns a NULL-terminated array of newly allocated strings. |
| `ft_itoa`       | Converts an integer to a newly allocated string (negative numbers handled).                     |
| `ft_strmapi`    | Applies `f(index, char)` to each character of `s` and returns the new resulting string.         |
| `ft_striteri`   | Applies `f(index, &char)` to each character of `s`, allowing in-place modification.             |
| `ft_putchar_fd` | Writes a character to the given file descriptor.                                                |
| `ft_putstr_fd`  | Writes a string to the given file descriptor.                                                   |
| `ft_putendl_fd` | Writes a string followed by a newline to the given file descriptor.                             |
| `ft_putnbr_fd`  | Writes an integer to the given file descriptor.                                                 |

### Part 3 – Linked lists

The following structure is defined in `libft.h`:

```c
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;
```

| Function          | Description                                                                                               |
| ----------------- | --------------------------------------------------------------------------------------------------------- |
| `ft_lstnew`       | Creates a new node with the given content; `next` is set to `NULL`.                                       |
| `ft_lstadd_front` | Adds a node at the beginning of the list.                                                                 |
| `ft_lstsize`      | Counts the number of nodes in the list.                                                                   |
| `ft_lstlast`      | Returns the last node of the list.                                                                        |
| `ft_lstadd_back`  | Adds a node at the end of the list.                                                                       |
| `ft_lstdelone`    | Frees a node's content with `del`, then the node itself (not the next one).                               |
| `ft_lstclear`     | Deletes and frees a node and all its successors, then sets the list pointer to `NULL`.                    |
| `ft_lstiter`      | Applies `f` to the content of each node.                                                                  |
| `ft_lstmap`       | Creates a new list by applying `f` to each node's content; uses `del` to clean up if an allocation fails. |

## Project structure

```
.
├── Makefile
├── README.md
├── libft.h
└── ft_*.c
```

## Resources

### References

- `man 3` pages of the reimplemented functions (`strlen`, `memmove`, `strlcpy`, `calloc`, etc.)
- The 42 Norm (official 42 documentation)
- `man ar` – GNU archiver
- GNU Make documentation: https://www.gnu.org/software/make/manual/
