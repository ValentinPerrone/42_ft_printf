/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_caster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaperron <vaperron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/01 02:10:24 by vaperron          #+#    #+#             */
/*   Updated: 2026/11/03 19:20:18 by vaperron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_caster(char c, va_list list)
{
	char	*substring;

	if (c == 'c')
		substring = va_arg(list, char *);
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
	return (substring);
}

int	ft_printer(char *string, int *counter)
{
	int		count;

	count = ft_terminal_write(string, '\0', counter, 0);
	return(count);
}