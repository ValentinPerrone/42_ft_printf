*This project has been created as part of the 42 curriculum by vaperron.*

# ft_printf

## Description

ft_printf is a custom re-implementation of the standard C library function printf(). The primary goal of this project is to discover and replicate the mechanics of variadic functions (<stdarg.h>) and formatted output handling in C.

The project parses format strings, identifies conversion specifiers and flags, casts arguments appropriately, and writes the formatted result to the standard output while returning the total number of characters printed. It supports standard conversion specifiers (c, s, p, d, i, u, x, X, %) as well as advanced formatting flags such as width, precision (.), left justification (-), zero padding (0), alternate forms (#), and sign alignments (+,  ).
## Instructions
### Compilation

To compile the library and generate the archive file (libftprintf.a), run the provided Makefile in the root directory:
Bash

make

Additional Makefile Rules

    make clean: Removes all object files (.o).

    make fclean: Removes object files and the compiled library (libftprintf.a).

    make re: Recompiles the entire project from scratch.

### Usage

Include the header file in your C source files:

```
#include "ft_printf.h"
```
Link libftprintf.a when compiling your program with gcc:

```
gcc main.c libftprintf.a -o my_program
```

Algorithm and Data Structure Justification
Data Structures

    Tracking State Array (int counter[2]):

        counter[0] tracks the current index position inside the main format string during parsing.

        counter[1] acts as an accumulated character count returned by ft_printf to match the standard behavior of tracking printed output length.

    Dynamic Substrings (char *):
    Arguments are converted into heap-allocated strings via dedicated caster helpers (ft_itoa, ft_hextoa, ft_c_assigner, etc.) before layout alignment and padding are applied. This decouples formatting logic from raw type representation.

### Algorithm Design

    Single-Pass Parsing & Counting:
    The function first calculates total argument requirements using ft_arg_number(). It then iterates through the format string via ft_printf() and ft_flag_checker(), cleanly separating literal text printing (ft_terminal_write) from formatted argument evaluation.

    Modular Flag Dispatching:
    Instead of a monolithic conditional block, flag modifiers (-, 0, #, +,  , .) are modularized into dedicated handler functions (ft_left_justification, ft_zero_padding, ft_hash_flag, etc.). This ensures clean separation of concerns and robust handling of flag override logic (e.g., precedence rules between plus/space or zero/precision formatting).

## References

    C Standard Library Documentation (<stdarg.h>, write, malloc, free)

    42 Curricula Guidelines for ft_printf

    ASCII and Two's Complement Bit Representation References

AI Usage Disclosure

Artificial Intelligence was utilized during the development of this project as a technical collaborator to:

    Brainstorm parsing strategies for flag precedence and override checks (ft_flag_override).

    Debug edge cases involving 64-bit unsigned hexadecimal conversions (ft_hextoa) and sign handling.

    Structure and write clear technical documentation and README guidelines.