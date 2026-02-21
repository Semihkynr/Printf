*This project has been created as part of the 42 curriculum by skaynar.*

# ft_printf

## Description

ft_printf is a reimplementation of the standard C `printf` function.

The goal of this project is to understand and reproduce formatted output using variadic arguments (`stdarg.h`) while respecting strict memory management and 42 coding standards.

Mandatory conversions implemented:

* `%c` character
* `%s` string
* `%d` / `%i` signed integer
* `%u` unsigned integer
* `%x` lowercase hexadecimal
* `%X` uppercase hexadecimal
* `%p` pointer address
* `%%` percent sign

The function returns the total number of characters printed.

---

## Instructions

### Compile

```bash
make
```

This generates:

```
libftprintf.a
```

### Usage

Include the header:

```c
#include "ft_printf.h"
```

Compile with:

```bash
cc main.c libftprintf.a -Wall -Wextra -Werror
```

Example:

```c
ft_printf("Number: %d\n", 42);
```

---

## Algorithm & Structure

The format string is parsed character by character.

* Normal characters are printed using `write()`.
* When `%` is found, the next character determines the conversion type.
* The corresponding argument is retrieved using `va_arg`.
* Each conversion has its own handler function.

Numeric conversions use recursive division to print digits in the correct order.
Pointers are cast to `unsigned long` before hexadecimal conversion.

A small structure is used to track the total printed character count.

---

## Resources

* `man 3 printf`
* `man 3 stdarg`
* The C Programming Language – K&R

### AI Usage

AI was used only for debugging edge cases and verifying behavior (e.g., unsigned handling and return values).
All implementation logic was written and understood manually.
