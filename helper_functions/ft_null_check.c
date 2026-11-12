/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_null_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaperron <vaperron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 22:17:27 by vaperron          #+#    #+#             */
/*   Updated: 2026/11/12 17:14:19 by vaperron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "helper_functions.h"

int	ft_null_check(char *string, int *counter)
{
	if (ft_strlen(string) == 0)
	{
		write(1, "(nil)", 5);
		counter[1] = counter[1] + 5;
		return (5);
	}
	else
	{
		write(1, "0x", 2);
		counter[1] = counter[1] + 2;
		return (2);
	}
}
