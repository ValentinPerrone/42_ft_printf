/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_caster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaperron <vaperron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/01 02:10:24 by vaperron          #+#    #+#             */
/*   Updated: 2026/11/03 17:14:45 by vaperron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_caster(char c, int *counter, va_list list)
{
	int		count;
	char	*substring;

	count = 0;
	if (c == 'c')
		count = ft_print_char(va_arg(list, int));
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
		count = ft_terminal_write(substring, '\0', counter, 0);
	if (c == 'p' || c == 'd' || c == 'i' || c == 'u' || c == 'x' || c == 'X')
		free(substring);
	return (count);
}