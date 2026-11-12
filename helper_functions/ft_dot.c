/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dot.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaperron <vaperron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 22:22:46 by vaperron          #+#    #+#             */
/*   Updated: 2026/11/12 17:13:17 by vaperron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "helper_functions.h"

void	ft_dot(size_t precision, const char *string, int *counter, va_list list)
{
	size_t	i;
	char	*arg_string;

	i = 0;
	while (ft_isalpha(string[counter[0]]) == 0)
		counter[0]++;
	arg_string = ft_caster(string[counter[0]], list);
	if (string[counter[0]] == 's')
	{
		while (i++ < precision && arg_string[i - 1])
		{
			write(1, &arg_string[i - 1], 1);
			counter[1]++;
		}
	}
	else
	{
		if (arg_string[0] == '-')
			ft_0_pr(precision + 1, string, counter, arg_string);
		else
			ft_0_pr(precision, string, counter, arg_string);
	}
	if (ft_strchr("cpdiuxX", string[counter[0]]) != NULL)
		free(arg_string);
	counter[0]++;
}
