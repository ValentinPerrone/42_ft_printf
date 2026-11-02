/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_terminal_write.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaperron <vaperron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 21:31:41 by vaperron          #+#    #+#             */
/*   Updated: 2026/11/02 23:35:06 by vaperron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_terminal_write(char const *string, char stopper_char, int *counter, int is_main_str)
{
	int		i;

	if(is_main_str = 1)
		i = counter[0];
	else
		i = 0;
	while(string[i])
	{
		if (string[i] == stopper_char)
			break;
		write(1, &string[i], 1);
		i++;
	}
	if (is_main_str = 1)
	{
		counter[1] = counter[1] + (i - counter[0])
	}
	
}
	