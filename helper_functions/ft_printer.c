/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaperron <vaperron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 22:18:07 by vaperron          #+#    #+#             */
/*   Updated: 2026/11/11 22:18:33 by vaperron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printer(char *string, int *counter, const char *main_string)
{
	int		count;

	count = 0;
	if(main_string[counter[0]] == 'p')
		count = ft_null_check(string, counter);
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
