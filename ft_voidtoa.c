/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_voidtoa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaperron <vaperron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 19:53:09 by vaperron          #+#    #+#             */
/*   Updated: 2026/11/05 16:17:28 by vaperron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int hex_size(unsigned long num)
{
	int		size;
	unsigned long		num_cpy;

	size = 0;
	num_cpy = num;
	while (num_cpy > 0)
	{
		num_cpy = num_cpy / 16;
		size++;
	}
	return (size);
}

char	*ft_voidtoa(unsigned long num)
{
	int		i;
	int		j;
	char	*dictionary;
	char	*result;
	
	if (!num)
		result = "(nil)\0";
	i = hex_size(num);
	j = i;
	dictionary = "0123456789abcdef";
	result = malloc((i + 1) * sizeof(char));
	if (!result)
		return(NULL);
	else
	{
		while (i > 0)
		{
			result[i + 3] = dictionary[num % 16];
			num = num / 16;
			i--;
		}
		result[0] = '0';
		result[1] = 'x';
		result[j] = '\0';
	}
	return (result);
}
