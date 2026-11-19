/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaperron <vaperron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 00:39:47 by vaperron          #+#    #+#             */
/*   Updated: 2026/11/19 16:31:40 by vaperron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(char const *string, ...)
{
	int		arg_ct;
	int		counter[2];
	va_list	list;
	char	*arg_str;

	arg_ct = ft_arg_number(string);
	va_start(list, string);
	ft_bzero(counter, (sizeof(int) * 2));
	while (string[counter[0]])
	{
		ft_twrite(string, '%', counter, 1);
		if (1 <= arg_ct--)
		{
			counter[0]++;
			arg_str = ft_caster(string[counter[0]], list);
			ft_printer(arg_str, counter, string);
			if (ft_strchr("cpdiuxX", string[counter[0]]) != NULL)
				free(arg_str);
			counter[0]++;
		}
	}
	va_end(list);
	return (counter[1]);
}
/*
int main(void)
{
	int mine = ft_printf("%-1c", '0');
	int orig = printf("%-1c", '0');
	printf("mine:%d original: %d", mine, orig);
	return (0);
}
*/