/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper_string.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaperron <vaperron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/02 16:23:46 by vaperron          #+#    #+#             */
/*   Updated: 2026/11/04 20:00:53 by vaperron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_toupper_string(char *string)
{
	int		i;

	i = 0;
	while (string[i])
	{
		if (string[i] >= 'a' && string[i] <= 'z')
			string[i] = string[i] - ('a' - 'A');
		i++;
	}
	return (string);
}
