/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_l_just.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaperron <vaperron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 22:22:52 by vaperron          #+#    #+#             */
/*   Updated: 2026/11/12 17:14:17 by vaperron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "helper_functions.h"

int	ft_l_just(int padding, const char *str, int *cntr, va_list list)
{
	int		i;
	int		character_ct;
	char	*arg_str;

	i = 0;
	while (ft_isalpha(str[cntr[0]]) == 0)
		cntr[0]++;
	arg_str = ft_caster(str[cntr[0]], list);
	character_ct = ft_printer(arg_str, cntr, str);
	if (ft_strchr("cpdiuxX", str[cntr[0]]) != NULL)
		free(arg_str);
	cntr[0]++;
	if (padding >= character_ct)
	{
		padding = padding - character_ct;
		if (padding != 0)
			cntr[1] = cntr[1] + padding;
		while (i++ < padding)
			write(1, " ", 1);
	}
	return (cntr[1]);
}
