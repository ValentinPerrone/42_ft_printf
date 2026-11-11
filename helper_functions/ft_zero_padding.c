/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zero_padding.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaperron <vaperron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 22:26:58 by vaperron          #+#    #+#             */
/*   Updated: 2026/11/11 23:17:37 by vaperron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


int	ft_zero_padding(size_t padding, const char *string, int *counter, va_list list)
{
	size_t	i;
	char	*arg_string;

	i = 0;
	while (ft_isalpha(string[counter[0]]) == 0)
		counter[0]++;
	arg_string = ft_caster(string[counter[0]], list);
	ft_zero_printing(string, arg_string, counter, i, padding);
	if (ft_strchr("cpdiuxX", string[counter[0]]) != NULL)
		free(arg_string);
	counter[0]++;
	return(counter[1]);
}
