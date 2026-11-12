/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hextoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaperron <vaperron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 19:53:09 by vaperron          #+#    #+#             */
/*   Updated: 2026/11/12 15:46:01 by vaperron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_functions.h"

static int	long_min_check(unsigned long long num)
{
	if ((long long)num <= -9223372036854775807)
		return (1);
	else
		return (0);
}

static int	hex_size(unsigned long long num)
{
	int		size;

	size = 0;
	if (num == 0)
		return (1);
	if (long_min_check(num) == 1)
		return (1);
	while (num > 0 && size < 8)
	{
		num = num / 16;
		size++;
	}
	return (size);
}

char	*ft_hextoa(unsigned long long num)
{
	int		i[2];
	char	*dictionary;
	char	*result;

	i[0] = hex_size(num);
	i[1] = i[0];
	dictionary = "0123456789abcdef";
	result = malloc((i[0] + 1) * sizeof(char));
	if (!result)
		return (NULL);
	else
	{
		while (i[0]-- > 0)
		{
			result[i[0]] = dictionary[num % 16];
			num = num / 16;
		}
	}
	result[i[1]] = '\0';
	return (result);
}
