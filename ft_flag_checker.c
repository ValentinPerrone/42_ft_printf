/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_checker.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaperron <vaperron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 02:43:50 by vaperron          #+#    #+#             */
/*   Updated: 2026/11/12 17:20:18 by vaperron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_flag_checker(const char *string, int *counter, va_list list)
{
	char	*arg_string;
	char	arg;

	arg = string[counter[0] + 1];
	if (arg == '#')
		ft_hash_flag(string, counter, list);
	else if (arg == ' ' && ft_flag_override(string, counter, '+') == 0)
		ft_sp_al(ft_atoi(&string[counter[0] + 1]), string, counter, list);
	else if (arg == '+')
		ft_pl_al(ft_atoi(&string[counter[0] + 1]), string, counter, list);
	else if (arg == '-' || (ft_isdigit(arg) == 1 && arg != '0'))
		ft_l_just(ft_atoi(&arg), string, counter, list);
	else if (arg == '0' && ft_flag_override(string, counter, '.') == 0)
		ft_0_padd(ft_atoi(&string[counter[0] + 2]), string, counter, list);
	else if (arg == '.')
		ft_dot(ft_atoi(&string[counter[0] + 2]), string, counter, list);
	else
	{
		arg_string = ft_caster(string[counter[0] + 1], list);
		ft_printer(arg_string, counter, string);
		if (ft_strchr("cpdiuxX", string[counter[0] + 1]) != NULL)
			free(arg_string);
		counter[0] = counter[0] + 2;
	}
	return (counter[1]);
}
