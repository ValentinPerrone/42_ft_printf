/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaperron <vaperron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/06 21:17:53 by vaperron          #+#    #+#             */
/*   Updated: 2026/11/12 15:36:48 by vaperron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_functions.h"

static int	ft_nint(int c)
{
	if (c == '\f' || c == '\n' || c == '\r')
		return (1);
	else if (c == '\t' || c == '\v' || c == ' ')
		return (1);
	else if (ft_isalpha(c) == 1)
		return (1);
	else if (ft_isdigit(c) != 1)
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	val;

	i = 0;
	val = 0;
	while (ft_nint(nptr[i]) == 1 || nptr[i] == '-')
		i++;
	while (ft_isdigit(nptr[i]) == 1)
	{
		val = val * 10 + (nptr[i] - '0');
		i++;
	}
	return (val);
}
