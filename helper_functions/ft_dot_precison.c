/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dot_precison.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaperron <vaperron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 22:22:46 by vaperron          #+#    #+#             */
/*   Updated: 2026/11/11 23:16:12 by vaperron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_dot_precision(size_t precision, const char *string, int *counter, va_list list)
{
	size_t	i;
	char	*arg_string;

	i = 0;
	while (ft_isalpha(string[counter[0]]) == 0)
		counter[0]++;
	arg_string = ft_caster(string[counter[0]], list);
	if (string[counter[0]] == 's')
	{
		while(i++ < precision && arg_string[i - 1])
		{
			write(1, &arg_string[i - 1], 1);
			counter[1]++;
		}
	}
	else
	{
		if (arg_string[0] == '-')
			ft_zero_printing(string, arg_string, counter, i, precision + 1);
		else
			ft_zero_printing(string, arg_string, counter, i, precision);
	}
	if (ft_strchr("cpdiuxX", string[counter[0]]) != NULL)
			free(arg_string);
	counter[0]++;
	return(counter[1]);
}