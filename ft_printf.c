/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaperron <vaperron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 00:39:47 by vaperron          #+#    #+#             */
/*   Updated: 2026/11/01 02:51:01 by vaperron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

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
		ft_flag_checker(string, string_pos, list);
		if (0 < arg_ct--)
			character_ct = character_ct + ft_caster(string[string_pos - 1], list);
	}
	va_end(list);
	return(character_ct);
}

int main(void)
{
	unsigned int hex = 4247582346;
	int num[1] = {42};
	//ft_printf("hola %c %s %p %d %i %u %x %X %% mundo\n", 'c', "test", &num, 1000, 1000, -1000, hex, hex);
	//printf("hola %c %s %p %d %i %u %x %X %% mundo\n", 'c', "test", &num, 1000, 1000, -1000, hex, hex);
	ft_printf("hola %-10d\n", 42);
	printf("hola %-10d\n", 42);
	return (0);
}
