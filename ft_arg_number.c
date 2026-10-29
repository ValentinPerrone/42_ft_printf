/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_number.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaperron <vaperron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 01:19:54 by vaperron          #+#    #+#             */
/*   Updated: 2026/10/27 20:09:13 by vaperron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_arg_number(char const *string)
{
	int	i;
	int	arg_number;

	i = 0;
	arg_number = 0;
	while (string[i])
	{
		if (string[i] == '%' && string[i + 1])
		{
			arg_number++;
			if (string[i+1] == '%')
				i++;
		}	
		i++;
	}
	return (arg_number);
}
