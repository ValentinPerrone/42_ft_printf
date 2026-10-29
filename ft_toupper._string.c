/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper._string.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaperron <vaperron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/02 16:23:46 by vaperron          #+#    #+#             */
/*   Updated: 2026/10/29 21:31:39 by vaperron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_toupper_string(char *string)
{
    int i;

    i = 0;
    while (string[i])
    {
        if (string[i] >= 'a' && string[i] <= 'z')
            string[i] = string[i] - ('a' - 'A');
    }
    return (string);
}
