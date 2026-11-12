/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_c_assigner.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaperron <vaperron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 22:15:55 by vaperron          #+#    #+#             */
/*   Updated: 2026/11/12 17:13:20 by vaperron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "helper_functions.h"

char	*ft_c_assigner(va_list list)
{
	char	*substring;

	substring = malloc(sizeof(char) * 2);
	if (!substring)
		return (NULL);
	substring[0] = (char)va_arg(list, int);
	substring[1] = '\0';
	return (substring);
}
