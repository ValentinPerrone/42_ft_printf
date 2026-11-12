/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaperron <vaperron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/02 23:24:53 by vaperron          #+#    #+#             */
/*   Updated: 2026/11/12 15:49:19 by vaperron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_functions.h"

char	*ft_strchr(const char *s, int c)
{
	char	character;

	character = (char)c;
	while (*s)
	{
		if (*s == character)
			return ((char *)s);
		s++;
	}
	if (*s == character)
		return ((char *)s);
	return (NULL);
}
