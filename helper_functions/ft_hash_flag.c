/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hash_flag.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaperron <vaperron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 22:22:50 by vaperron          #+#    #+#             */
/*   Updated: 2026/11/11 22:24:37 by vaperron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hash_flag(const char *string, int *counter, va_list list)
{
	char	*arg_string;
	
	while (ft_isalpha(string[counter[0]]) == 0)
		counter[0]++;
	arg_string = ft_caster(string[counter[0]], list);
	if(arg_string[0] != '0')
	{
		if(string[counter[0]] == 'x' )
			write(1, "0x", 2);
		else if(string[counter[0]] == 'X')
			write(1, "0X", 2);
		counter[1] = counter[1] + 2;
	}
	ft_printer(arg_string, counter, string);
	if (ft_strchr("cpdiuxX", string[counter[0]]) != NULL)
			free(arg_string);
	counter[0]++;
	return(counter[1]);
}