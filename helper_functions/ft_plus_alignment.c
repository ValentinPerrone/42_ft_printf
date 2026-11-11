/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_plus_alignment.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaperron <vaperron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 22:23:00 by vaperron          #+#    #+#             */
/*   Updated: 2026/11/11 22:25:29 by vaperron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_plus_alignment(size_t padding, const char *string, int *counter, va_list list)
{
	char	*arg_string;

	counter[0]++;
	while (ft_isalpha(string[counter[0]]) == 0)
		counter[0]++;
	arg_string = ft_caster(string[counter[0]] , list);
	if (padding > ft_strlen(arg_string))
	{
		if(arg_string[0] != '-')
			padding--;
		padding = padding - ft_strlen(arg_string);
		if (padding != 0)
			counter[1] = counter[1] + padding;
		while(padding-- > 0)
			write(1, " ", 1);
	}
	if(arg_string[0] != '-')
	{
		write(1, "+", 1);
		counter[1]++;
	}
	if(ft_strlen(arg_string) != 0)
		ft_printer(arg_string, counter, string);
	if (ft_strchr("cpdiuxX", string[counter[0]]) != NULL)
		free(arg_string);
	counter[0]++;
}
