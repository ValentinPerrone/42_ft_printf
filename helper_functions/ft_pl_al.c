/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pl_al.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaperron <vaperron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 22:23:00 by vaperron          #+#    #+#             */
/*   Updated: 2026/11/12 17:42:51 by vaperron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "helper_functions.h"

void	ft_pl_al(size_t padding, const char *str, int *cntr, va_list list)
{
	char	*arg_str;

	while (ft_isalpha(str[cntr[0] + 1]) == 0)
		cntr[0]++;
	arg_str = ft_caster(str[cntr[0] + 1], list);
	if (padding > ft_strlen(arg_str))
	{
		if (arg_str[0] != '-')
			padding--;
		padding = padding - ft_strlen(arg_str);
		if (padding != 0)
			cntr[1] = cntr[1] + padding;
		while (padding-- > 0)
			write(1, " ", 1);
	}
	if (arg_str[0] != '-')
	{
		write(1, "+", 1);
		cntr[1]++;
	}
	if (ft_strlen(arg_str) != 0)
		ft_printer(arg_str, cntr, str);
	if (ft_strchr("cpdiuxX", str[cntr[0] + 1]) != NULL)
		free(arg_str);
	cntr[0] = cntr[0] + 2;
}
