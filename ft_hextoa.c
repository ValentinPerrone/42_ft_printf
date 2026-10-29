/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hextoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaperron <vaperron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 19:53:09 by vaperron          #+#    #+#             */
/*   Updated: 2026/10/29 21:54:00 by vaperron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
static int hex_size(unsigned long num)
{
	int		size;
	int		num_cpy;

	size = 0;
	num_cpy = num;
	while (num_cpy > 0)
	{
		num_cpy = num_cpy / 16;
		size++;
	}
	return (size);
}

char	*ft_hextoa(unsigned long num)
{
	int		i;
	char	*dictionary;
	char	*result;

	i = hex_size(num);
	dictionary = "0123456789abcdef";
	result = malloc((i + 1) * sizeof(char));
	if (!result)
		return(NULL);
	if (!num)
		result = "(nil)\0";
	else
	{
		while (i > 0)
		{
			result[i] = dictionary[num % 16];
			num = num / 16;
			i--;
		}
		result[16] = '\0';
	}
	return (result);
}
