/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaperron <vaperron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 00:39:47 by vaperron          #+#    #+#             */
/*   Updated: 2026/10/28 15:59:42 by vaperron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	caster(char c, va_list list, int character_ct)
{
	char	*substring;
	if (c == 'c')
		substring = va_arg(list, char *);
	else if (c == 's')
		substring = va_arg(list, char *);
	else if (c == 'p')
	{
		write(1, "0x", 2);
		substring = ft_hextoa(va_arg(list, unsigned long));
	}
	else if (c == 'd')
		substring = ft_itoa(va_arg(list, int));
	else if (c == 'i')
		substring = ft_itoa(va_arg(list, int));
	else if (c == 'u')
		substring = ft_itoa(ft_abs_val(va_arg(list, int)));
	else if (c == 'x')
		substring = ft_hextoa(va_arg(list, unsigned long));
	else if (c == 'X')
		substring = ft_toupper_string(ft_hextoa(va_arg(list, unsigned long)));
	else if (c == '%')
			substring = "%";
	character_ct = character_ct + ft_terminal_write(substring, '\0', 0);
	if (c == 'p' || c == 'd' || c == 'i' || c == 'u' || c == 'x' || c == 'X')
		free(substring);
}

int	ft_printf(char const *string, ...)
{
	int		i;
	int		arg_ct;
	int		character_ct;
	va_list	list;

	i = 0;
	character_ct = 0;
	arg_ct = ft_arg_number(string);
	va_start(list, string);
	while(string[character_ct])
	{
		ft_terminal_write((char *)string, '%', character_ct);
		if (string[character_ct] == '%')
			character_ct = character_ct + 2;
		if (i < arg_ct)
		{
			caster(string[character_ct - 1], list, character_ct );
			i++;
		}
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
