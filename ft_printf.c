/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaperron <vaperron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 00:39:47 by vaperron          #+#    #+#             */
/*   Updated: 2026/11/09 20:22:27 by vaperron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(char const *string, ...)
{
	int		arg_ct;
	int		counter[2];// 1st argument is for main string positioning, second argument is for total characters printed
	va_list	list;

	arg_ct = ft_arg_number(string);
	va_start(list, string);
	ft_bzero(counter, (sizeof(int) * 2));
	while(string[counter[0]])
	{
		ft_terminal_write(string, '%', counter, 1);
		if (1 <= arg_ct--)
			ft_flag_checker(string, counter, list);
	}
	va_end(list);
	return(counter[1]);
}
/*
int main(void)
{
	//unsigned int hex = 4247582346;
	//int num[1] = {42};
	//ft_printf("hola %c %s %p %d %i %u %x %X %% mundo\n", 'c', "test", &num, 1000, 1000, -1000, hex, hex);
	//printf("hola %c %s %p %d %i %u %x %X %% mundo\n", 'c', "test", &num, 1000, 1000, -1000, hex, hex);
	int mine = ft_printf(" %x %x %x %x %x %x %x\n", 2147483647, -2147483648, 9223372036854775807, -9223372036854775808, 18446744073709551615, 0, -42);//ft_printf("hola %010.5d test %s\n", 42, "words");
	int original = printf(" %x %x %x %x %x %x %x\n", 2147483647, -2147483648, 9223372036854775807, -9223372036854775808, 18446744073709551615, 0, -42);//printf("hola %.5d test %s\n", 42, "words");
	printf("mine: %d original: %d\n", mine, original);
	return (0);
}
*/