/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_terminal_write.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaperron <vaperron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 21:31:41 by vaperron          #+#    #+#             */
/*   Updated: 2026/11/01 02:32:58 by vaperron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_terminal_write(char const *string, char stopper_char, int character_ct)
{
	while(string[character_ct])
	{
		if (string[character_ct] == stopper_char)
		{
			return (character_ct);
		}
		write(1, &string[character_ct], 1);
		character_ct ++;
	}
    return (character_ct);
}
