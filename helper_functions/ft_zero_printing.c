/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zero_printing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaperron <vaperron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 22:23:02 by vaperron          #+#    #+#             */
/*   Updated: 2026/11/11 22:26:08 by vaperron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_zero_printing(const char *string, char *arg_string, int *counter, size_t i, size_t padding)
{
	if (arg_string[0] == '-')
	{
		write(1, "-", 1);
		counter[1]++;
	}
	if (padding > ft_strlen(arg_string))
	{
		padding = padding - ft_strlen(arg_string);
		counter[1] = counter[1] + padding;
		while(i++ < padding)
			write(1, "0", 1);
	}
	if (arg_string[0] == '-')
		ft_printer(arg_string + 1, counter, string);
	else
		ft_printer(arg_string, counter, string);
}
