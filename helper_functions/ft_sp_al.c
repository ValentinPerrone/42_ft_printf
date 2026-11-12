/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sp_al.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaperron <vaperron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 22:26:25 by vaperron          #+#    #+#             */
/*   Updated: 2026/11/12 17:42:54 by vaperron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "helper_functions.h"

void	ft_sp_al(size_t padding, const char *str, int *cntr, va_list list)
{
	char	*arg_str;

	cntr[0]++;
	while (ft_isalpha(str[cntr[0]]) == 0)
		cntr[0]++;
	arg_str = ft_caster(str[cntr[0]], list);
	if (ft_strlen(arg_str) != 0 && str[cntr[0]] != 's' && arg_str[0] != '-')
	{
		write(1, " ", 1);
		cntr[1]++;
	}
	if (padding > ft_strlen(arg_str))
	{
		padding = padding - ft_strlen(arg_str);
		if (padding != 0)
			cntr[1] = cntr[1] + padding;
		while (padding-- > 0)
			write(1, " ", 1);
	}
	if (ft_strlen(arg_str) != 0)
		ft_printer(arg_str, cntr, str);
	if (ft_strchr("cpdiuxX", str[cntr[0]]) != NULL)
		free(arg_str);
	cntr[0]++;
}
