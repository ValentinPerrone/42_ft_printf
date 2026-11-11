/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaperron <vaperron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 00:39:47 by vaperron          #+#    #+#             */
/*   Updated: 2026/11/11 19:25:47 by vaperron         ###   ########.fr       */
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
//	int mine1 = ft_printf("_%-1c_\n", '0');
//	int original1 = printf("_%-1c_\n", '0');
//	printf("mine: %d original: %d\n", mine1, original1);
//	int mine2 = ft_printf("_%-2c_\n", 0);
//	int original2 = printf("_%-2c_\n", 0);
//	printf("mine: %d original: %d\n", mine2, original2);
//	int mine3 = ft_printf(".%02d.", 11);
//	int original3 = printf(".%02d.", 11);
//	printf("mine: %d original: %d\n", mine3, original3);
	int mine = ft_printf(".%#x.\n", 0);
	int original = printf(".%#x.\n", 0);
	printf("mine: %d original: %d\n", mine, original);
	return (0);
}
*/