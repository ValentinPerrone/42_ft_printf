/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hextoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaperron <vaperron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 19:53:09 by vaperron          #+#    #+#             */
/*   Updated: 2026/11/06 23:09:25 by vaperron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int hex_size(long long num, char c)
{
	int		size;
	unsigned long		num_cpy;

	if(c == 'p' || num != 0)
		size = 0;
	else
		size = 1;
	num_cpy = num;
	while (num_cpy > 0 && size < 8)
	{
		num_cpy = num_cpy / 16;
		size++;
	}
	return (size);
}

char	*ft_hextoa(long long num, char c)
{
	int		i;
	int		j;
	char	*dictionary;
	char	*result;
	
	if (!num)
		result = "(nil)\0";
	i = hex_size(num, c);
	j = i;
	dictionary = "0123456789abcdef";
	result = malloc((i + 1) * sizeof(char));
	if (!result)
		return(NULL);
	else
	{
		while (i > 0)
		{
			result[i - 1] = dictionary[num % 16];
			num = num / 16;
			i--;
		}
		result[j] = '\0';
	}
	return (result);
}
