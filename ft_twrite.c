/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_twrite.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaperron <vaperron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 21:31:41 by vaperron          #+#    #+#             */
/*   Updated: 2026/11/12 17:40:14 by vaperron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_twrite(char const *string, char st_char, int *cntr, int main)
{
	int		i;

	if (main == 1)
		i = cntr[0];
	else
		i = 0;
	while (string[i])
	{
		if (string[i] == st_char)
			break ;
		write(1, &string[i], 1);
		i++;
	}
	if (main == 1)
	{
		cntr[1] = cntr[1] + (i - cntr[0]);
		cntr[0] = i;
	}
	else
		cntr[1] = cntr[1] + i;
	return (i);
}
