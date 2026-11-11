/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_space_alignment.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaperron <vaperron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 22:26:25 by vaperron          #+#    #+#             */
/*   Updated: 2026/11/11 22:26:48 by vaperron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_space_alignment(size_t padding, const char *string, int *counter, va_list list)
{
	char	*arg_string;

	counter[0]++;
	while (ft_isalpha(string[counter[0]]) == 0)
		counter[0]++;
	arg_string = ft_caster(string[counter[0]] , list);
	if(ft_strlen(arg_string) != 0 && string[counter[0]] != 's' && arg_string[0] != '-')
	{
		write(1, " ", 1);
		counter[1]++;
	}
	if (padding > ft_strlen(arg_string))
	{
		padding = padding - ft_strlen(arg_string);
		if (padding != 0)
			counter[1] = counter[1] + padding;
		while(padding-- > 0)
			write(1, " ", 1);
	}
	if(ft_strlen(arg_string) != 0)
		ft_printer(arg_string, counter, string);
	if (ft_strchr("cpdiuxX", string[counter[0]]) != NULL)
		free(arg_string);
	counter[0]++;
}