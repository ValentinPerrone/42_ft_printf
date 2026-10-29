/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_voidtoa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaperron <vaperron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 19:53:09 by vaperron          #+#    #+#             */
/*   Updated: 2026/10/30 00:38:41 by vaperron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_voidtoa(unsigned long num)
{
	int		i;
	char	*dictionary;
	char	*result;

	if (!num)
		result = "(nil)\0";
	i = 2;
	dictionary = "0123456789abcdef";
	result = malloc(16 * sizeof(char));
	if (!result)
		return(NULL);
	else
	{
		while (i <= 13)
		{
			result[15 - i] = dictionary[num % 16];
			num = num / 16;
			i++;
		}
		result[0] = '0';
		result[1] = 'x';
		result[16] = '\0';
	}
	return (result);
}
