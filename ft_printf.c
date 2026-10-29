/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaperron <vaperron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 00:39:47 by vaperron          #+#    #+#             */
/*   Updated: 2026/10/30 00:49:34 by vaperron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	caster(char c, va_list list)
{
	int count;
	unsigned int num;

	count = 0;
	char	*substring;
	if (c == 'c')
		count = count + ft_print_char(va_arg(list, int));
	else if (c == 's')
		substring = va_arg(list, char *);
	else if (c == 'p')
		substring = ft_voidtoa(va_arg(list, unsigned long));
	else if (c == 'd' || c == 'i')
		substring = ft_itoa(va_arg(list, int));
	else if (c == 'u')
		substring = ft_utoa(va_arg(list, unsigned int));
	else if (c == 'x')
		substring = ft_hextoa(va_arg(list, unsigned long));
	else if (c == 'X')
		substring = ft_toupper_string(ft_hextoa(va_arg(list, unsigned long)));
	else if (c == '%')
			substring = "%";
	if (c != 'c')
		count = count + ft_terminal_write(substring, '\0', 0);
	if (c == 'p' || c == 'd' || c == 'i' || c == 'u' || c == 'x' || c == 'X')
		free(substring);
	return (count);
}

int	ft_printf(char const *string, ...)
{
	int		arg_ct;
	int		character_ct;
	int		string_pos;
	va_list	list;

	character_ct = 0;
	string_pos = 0;
	arg_ct = ft_arg_number(string);
	va_start(list, string);
	while(string[string_pos])
	{
		string_pos = ft_terminal_write(string, '%', string_pos);
		if (string[string_pos] == '%')
			string_pos = string_pos + 2;
		if (0 < arg_ct--)
			character_ct = character_ct + caster(string[string_pos - 1], list);
	}
	va_end(list);
	return(character_ct);
}

int main(void)
{
	unsigned int hex = 4247582346;
	int num[1] = {42};
	ft_printf("hola %c %s %p %d %i %u %x %X %% mundo\n", 'c', "test", &num, 1000, 1000, -1000, hex, hex);
	printf("hola %c %s %p %d %i %u %x %X %% mundo\n", 'c', "test", &num, 1000, 1000, -1000, hex, hex);
	return (0);
}
