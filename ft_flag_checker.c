/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_checker.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaperron <vaperron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 02:43:50 by vaperron          #+#    #+#             */
/*   Updated: 2026/11/11 22:27:18 by vaperron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_flag_checker(const char *string, int *counter, va_list list)
{
	char *arg_string;
	if (string[counter[0] + 1] == '#')
		ft_hash_flag(string, counter, list);
	else if (string[counter[0] + 1] == ' ' && ft_flag_override(string, counter, '+') == 0)
		ft_space_alignment(ft_atoi(&string[counter[0] + 1]), string, counter, list);
	else if (string[counter[0] + 1] == '+')
		ft_plus_alignment(ft_atoi(&string[counter[0] + 1]), string, counter, list);
	else if (string[counter[0] + 1] == '-' || (ft_isdigit(string[counter[0] + 1]) == 1 && string[counter[0] + 1] != '0'))
		ft_left_justification(ft_atoi(&string[counter[0] + 1]), string, counter, list);
	else if (string[counter[0] + 1] == '0' && ft_flag_override(string, counter, '.') == 0)
		ft_zero_padding(ft_atoi(&string[counter[0] + 2]), string, counter, list);
	else if (string[counter[0] + 1] == '.')
		ft_dot_precision(ft_atoi(&string[counter[0] + 2]), string, counter, list);
	else
	{
		counter[0]++;
		arg_string = ft_caster(string[counter[0]], list);
		ft_printer(arg_string, counter, string);
	if (ft_strchr("cpdiuxX", string[counter[0]]) != NULL)
			free(arg_string);
		counter[0]++;
	}
	return(counter[1]);
}