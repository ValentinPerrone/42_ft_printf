/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_override.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaperron <vaperron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 22:22:48 by vaperron          #+#    #+#             */
/*   Updated: 2026/11/12 17:13:12 by vaperron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "helper_functions.h"

int	ft_flag_override(const char *string, int *counter, char character)
{
	int	i;

	i = 0;
	while (ft_isalpha(string[counter[0] + i]) == 0)
	{
		if (string[counter[0] + i] == character)
			break ;
		i++;
	}
	if (string[counter[0] + i] == character)
	{
		counter[0] = counter[0] + (i - 1);
		return (1);
	}
	return (0);
}
