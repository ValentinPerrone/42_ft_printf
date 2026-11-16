/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_0_padd_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaperron <vaperron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 22:26:58 by vaperron          #+#    #+#             */
/*   Updated: 2026/11/14 02:17:12 by vaperron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_0_padd(size_t padding, const char *str, int *cntr, va_list list)
{
	char	*arg_str;

	while (ft_isalpha(str[cntr[0]]) == 0)
		cntr[0]++;
	arg_str = ft_caster(str[cntr[0]], list);
	ft_0_pr(padding, str, cntr, arg_str);
	if (ft_strchr("cpdiuxX", str[cntr[0]]) != NULL)
		free(arg_str);
	cntr[0]++;
	return (cntr[1]);
}
