/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_checker.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaperron <vaperron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 02:43:50 by vaperron          #+#    #+#             */
/*   Updated: 2026/11/12 18:09:36 by vaperron         ###   ########.fr       */
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

int	ft_flag_checker(const char *s, int *c, va_list list)
{
	char	*arg_s;

	if (s[c[0] + 1] == '#')
		ft_hash_flag(s, c, list);
	else if (s[c[0] + 1] == ' ' && ft_flag_override(s, c, '+') == 0)
		ft_sp_al(ft_atoi(&s[c[0] + 1]), s, c, list);
	else if (s[c[0] + 1] == '+')
		ft_pl_al(ft_atoi(&s[c[0] + 1]), s, c, list);
	else if (s[c[0] + 1] == '-' || not_0(s[c[0] + 1]) == 1)
		ft_l_just(ft_atoi(&s[c[0] + 1]), s, c, list);
	else if (s[c[0] + 1] == '0' && ft_flag_override(s, c, '.') == 0)
		ft_0_padd(ft_atoi(&s[c[0] + 2]), s, c, list);
	else if (s[c[0] + 1] == '.')
		ft_dot(ft_atoi(&s[c[0] + 2]), s, c, list);
	else
	{
		c[0]++;
		arg_s = ft_caster(s[c[0]], list);
		ft_printer(arg_s, c, s);
		if (ft_strchr("cpdiuxX", s[c[0]]) != NULL)
			free(arg_s);
		c[0]++;
	}
	return (c[1]);
}
