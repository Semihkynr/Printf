[README_PRINTF.md](https://github.com/user-attachments/files/23425763/README_PRINTF.md)
# ft_printf

A custom implementation of the `printf` function in C, developed as part of the **42 School curriculum**.  
This project focuses on formatted output handling, variadic functions, and efficient memory management.

---

## 📘 Overview

The **ft_printf** function replicates the behavior of the standard C library function `printf`.  
It handles formatted output by parsing the format string and processing multiple data types.

---

## ⚙️ Features

- Handles the following conversion specifiers:
  - `%c` — character
  - `%s` — string
  - `%p` — pointer (in hexadecimal format)
  - `%d` / `%i` — signed decimal integer
  - `%u` — unsigned decimal integer
  - `%x` / `%X` — hexadecimal integer (lowercase/uppercase)
  - `%%` — prints a percent sign

- Implements variadic arguments using `<stdarg.h>`.
- Supports modular and maintainable structure.
- Strictly follows the **42 Norm** coding style.

---

## 🧠 Key Concepts

- **Variadic Functions (`va_list`)**
- **Format String Parsing**
- **Buffer Management**
- **Memory Safety**

---

## 🧪 Example Usage

```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("Hello %s! You scored %d%% on the test.\n", "Semih", 100);
    return 0;
}
```

**Output:**
```
Hello Semih! You scored 100% on the test.
```

---
---

## 🧰 Compilation

```bash
make
```

This will generate the `libftprintf.a` static library file.

---

## 🧾 Usage

You can compile a program using your `ft_printf` library like this:

```bash
cc main.c libftprintf.a -o test_printf
./test_printf
```

---

## 🧹 Cleaning

```bash
make clean     # Remove object files
make fclean    # Remove object files + library
make re        # Rebuild everything
```


## 🏁 Status

✅ Finished (No Bonus)
