/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hextoa.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaperron <vaperron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 19:53:09 by vaperron          #+#    #+#             */
/*   Updated: 2026/10/28 15:23:03 by vaperron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*hextoa(unsigned int long long num)
{
	int		i;
	unsigned int long long		res_num;
	char	*dictionary;
	char	*result;

	i = 13;
	dictionary = "0123456789abcdef";
	result = malloc(16 * sizeof(char)); //8 bytes per memory address, 3 for 0x plus null terminator
	//result = "0x";
	while (i > 0)
	{
		res_num = num % 16;
		result[i] = dictionary[res_num];
		num = num / 16;
		i--;
	}
	result[0] = '0';
	result[1] = 'x';
	result[16] = '\0';
	return (result);
}