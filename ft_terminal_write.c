#include "libftprintf.h"

int ft_terminal_write(char *string, char stopper_char, int current_pos)
{
    while(string[current_pos] || string[current_pos] != stopper_char)
    {
        write(1, &string[current_pos], 1);
        current_pos++;
    }
    return(current_pos);
}
