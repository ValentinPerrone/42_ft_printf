/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_checker.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaperron <vaperron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 02:43:50 by vaperron          #+#    #+#             */
/*   Updated: 2026/11/12 18:56:54 by vaperron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	not_0(char arg)
{
	if (ft_isdigit(arg) == 1 && arg != '0')
		return (1);
	else
		return (0);
}

int	ft_flag_checker(const char *str, int *cntr, va_list list)
{
	char	*arg_str;

	if (str[cntr[0] + 1] == '#')
		ft_hash_flag(str, cntr, list);
	else if (str[cntr[0] + 1] == ' ' && ft_flag_override(str, cntr, '+') == 0)
		ft_sp_al(ft_atoi(&str[cntr[0] + 1]), str, cntr, list);
	else if (str[cntr[0] + 1] == '+')
		ft_pl_al(ft_atoi(&str[cntr[0] + 1]), str, cntr, list);
	else if (str[cntr[0] + 1] == '-' || not_0(str[cntr[0] + 1]) == 1)
		ft_l_just(ft_atoi(&str[cntr[0] + 1]), str, cntr, list);
	else if (str[cntr[0] + 1] == '0' && ft_flag_override(str, cntr, '.') == 0)
		ft_0_padd(ft_atoi(&str[cntr[0] + 2]), str, cntr, list);
	else if (str[cntr[0] + 1] == '.')
		ft_dot(ft_atoi(&str[cntr[0] + 2]), str, cntr, list);
	else
	{
		cntr[0]++;
		arg_str = ft_caster(str[cntr[0]], list);
		ft_printer(arg_str, cntr, str);
		if (ft_strchr("cpdiuxX", str[cntr[0]]) != NULL)
			free(arg_str);
		cntr[0]++;
	}
	return (str[1]);
}
