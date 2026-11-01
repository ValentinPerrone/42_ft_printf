/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaperron <vaperron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 15:10:22 by vaperron          #+#    #+#             */
/*   Updated: 2026/11/01 02:45:09 by vaperron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ascii_ins(long int n, int size, int exp, char *number)
{
	int		neg;
	int		ct;

	ct = 0;
	neg = 0;
	if (n < 0)
		neg = 1;
	if (neg == 1)
	{
		number[0] = '-';
		n = -n;
		ct++;
	}
	while (ct < (size + neg))
	{
		number[ct] = (n / exp) + '0';
		n = n - ((n / exp) * exp);
		exp = exp / 10;
	ct++;
	}
	return (ct);
}

char	*ft_utoa(unsigned int n)
{
	long int	n_long;
	long int	exp;
	int		neg;
	int		size;
	char	*number;

	exp = 1;
	size = 1;
	n_long = n;
	while ((n / (exp * 10)) != 0)
	{
		exp = exp * 10;
		size++;
	}
	number = malloc((size + neg + 1) * sizeof(char));
	if (!number)
		return (NULL);
	number[ascii_ins(n_long, size, exp, number)] = '\0';
	return (number);
}
