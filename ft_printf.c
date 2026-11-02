/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaperron <vaperron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 00:39:47 by vaperron          #+#    #+#             */
/*   Updated: 2026/11/02 23:42:38 by vaperron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_printf(char const *string, ...)
{
	int		arg_ct;
	int		counter[2];// 1st argument is for main string positioning, second argument is for total characters printed
	va_list	list;

	arg_ct = ft_arg_number(string);
	va_start(list, string);
	
	while(string[counter[0]])
	{
		string_pos = ft_terminal_write(string, '%', string_pos);
		string_pos = ft_flag_checker(string, string_pos, list);
		if (1 < arg_ct--)
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
	ft_printf("hola %-20d %s\n", 424242, "words");
	printf("hola %-20d %s\n", 424242, "words");
	return (0);
}
