/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_caster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaperron <vaperron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/01 02:10:24 by vaperron          #+#    #+#             */
/*   Updated: 2026/11/10 20:13:14 by vaperron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*c_assigner(va_list list)
{
	char	*substring;
	substring = malloc(sizeof(char) * 2);
	if (!substring)
		return (NULL);
	substring[0] = (char)va_arg(list, int);
	substring[1] = '\0';
	return (substring);
}

char	*ft_caster(char c, va_list list)
{
	char	*substring;

	if (c == 'c')
		substring = c_assigner(list);
	else if (c == 's')
		substring = va_arg(list, char *);
	else if (c == 'd' || c == 'i')
		substring = ft_itoa(va_arg(list, int));
	else if (c == 'u')
		substring = ft_utoa(va_arg(list, unsigned int));
	else if (c == 'p')
		substring = ft_voidtoa(va_arg(list, unsigned long), c);
	else if (c == 'x')
		substring = ft_hextoa(va_arg(list, unsigned int));
	else if (c == 'X')
		substring = ft_toupper_string(ft_hextoa(va_arg(list, unsigned int)));
	else
		substring = "%";
	return (substring);
}

static int null_check(char *string, int *counter)
{
	if(ft_strlen(string) == 0)
	{
		write(1, "(nil)", 5);
		counter[1] = counter[1] + 5;
		return(5);	
	}
	else
	{
		write(1, "0x", 2);
		counter[1] = counter[1] + 2;
		return(2);
	}
}

int	ft_printer(char *string, int *counter, const char *main_string)
{
	int		count;

	count = 0;
	if(main_string[counter[0]] == 'p')
		count = null_check(string, counter);
	if(main_string[counter[0]] == 'c' && string[0] == '\0')
	{
		count = 1;
		write(1, &string[0], 1);
		counter[1]++;
	}
	else
	{
		if (!string)	
		{
			count = 6;
			write(1, "(null)", 6);
			counter[1] = counter[1] + count;
		}
		else
			count = count + ft_terminal_write(string, '\0', counter, 0);
	}
	return(count);
}
