/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_checker.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaperron <vaperron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 02:43:50 by vaperron          #+#    #+#             */
/*   Updated: 2026/11/01 03:22:09 by vaperron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	left_justification(int padding, char *string, int string_pos, va_list list)
{
	int characters_ct;
	int	i;

	i = 0;
	padding = -padding;
	while (ft_isalpha(string[string_pos]) == 0)
		string_pos++;
	characters_ct = ft_caster(string[string_pos], list);
	if (padding > characters_ct)
	{
		padding = padding - characters_ct;
		while(i++ < padding)
		{
			write(1, " ", 1);
		}
	}
	return(padding);
}

int	ft_flag_checker(const char *string, int string_pos, va_list list)
{
	char    c;

	c = string[string_pos + 1];
	if (c == '-')
		left_justification(ft_atoi(&string[string_pos + 1]), string, string_pos, list);
	else if (c == '0')
		write(1, "h", 1);//do something
	else if (c == '.')
		write(1, "h", 1);//do something
	else if (c == '#')
		write(1, "h", 1);//do something
	else if (c == ' ')
		write(1, "h", 1);//do something
	else if (c == '+')
		write(1, "h", 1);//do something
}