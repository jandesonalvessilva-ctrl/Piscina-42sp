*This project has been created as part of the 42 curriculum by jaalves-.*

# ft_printf

## Description

Recoding of the C standard library function `printf()`. The function `ft_printf` handles variable arguments via `stdarg.h` and writes formatted output to the standard output, returning the total number of characters printed.

### Supported conversions

| Specifier | Description |
|-----------|-------------|
| `%c` | Single character |
| `%s` | String (NULL prints `(nil)`) |
| `%p` | Pointer in hexadecimal |
| `%d` / `%i` | Signed decimal integer |
| `%u` | Unsigned decimal integer |
| `%x` | Lowercase hexadecimal |
| `%X` | Uppercase hexadecimal |
| `%%` | Percent sign |

## Instructions

```sh
make        # builds libftprintf.a
make clean  # removes object files
make fclean # removes object files and library
make re     # full rebuild
```

## Resources

- `man 3 printf`
- `man 3 stdarg`
- [Variadic functions in C](https://en.cppreference.com/w/c/variadic)

**AI usage:** AI assisted with the initial project structure, test file generation and overall assistance with smaller aspects like README formatting and double-checking requirements.
