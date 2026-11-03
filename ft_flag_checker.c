/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_checker.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaperron <vaperron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 02:43:50 by vaperron          #+#    #+#             */
/*   Updated: 2026/11/03 17:36:27 by vaperron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	left_justification(int padding, const char *string, int *counter, va_list list)
{
	int	i;
	int	character_ct;

	i = 0;
	while (ft_isalpha(string[counter[0]]) == 0)
		counter[0]++;
	character_ct = ft_caster(string[counter[0]], counter, list);
	counter[0]++;
	if (padding > character_ct)
	{
		counter[1] = counter[1] + padding;
		padding = padding - character_ct;
		while(i++ < padding)
			write(1, " ", 1);
	}
	else
		counter[1] = counter[1] + character_ct;
	return(counter[1]);
}

int	ft_flag_checker(const char *string, int *counter, va_list list)
{
	char    c;

	c = string[counter[0] + 1];
	if (c == '-')
		left_justification(-ft_atoi(&string[counter[0] + 1]), string, counter, list);
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
	else
	{
		ft_caster(c, counter, list);
		counter[0] = counter[0] + 2;
	}
	return(counter[1]);
}