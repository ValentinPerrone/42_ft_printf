/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_terminal_write.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaperron <vaperron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 21:31:41 by vaperron          #+#    #+#             */
/*   Updated: 2026/10/29 21:31:42 by vaperron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int ft_terminal_write(char *string, char stopper_char, int current_pos)
{
    while(string[current_pos] || string[current_pos] != stopper_char)
    {
        write(1, &string[current_pos], 1);
        current_pos++;
    }
    return(current_pos);
}
