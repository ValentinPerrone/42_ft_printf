/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_left_justification.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaperron <vaperron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 22:22:52 by vaperron          #+#    #+#             */
/*   Updated: 2026/11/11 22:25:10 by vaperron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_left_justification(int padding, const char *string, int *counter, va_list list)
{
	int	i;
	int	character_ct;
	char	*arg_string;

	i = 0;
	while (ft_isalpha(string[counter[0]]) == 0)
		counter[0]++;
	arg_string = ft_caster(string[counter[0]], list);
	character_ct = ft_printer(arg_string, counter, string);
	if (ft_strchr("cpdiuxX", string[counter[0]]) != NULL)
			free(arg_string);
	counter[0]++;
	if (padding >= character_ct)
	{
		padding = padding - character_ct;
		if (padding != 0)
			counter[1] = counter[1] + padding;
		while(i++ < padding)
			write(1, " ", 1);
	}
	return(counter[1]);
}