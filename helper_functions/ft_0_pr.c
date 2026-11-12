/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_0_pr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaperron <vaperron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 22:23:02 by vaperron          #+#    #+#             */
/*   Updated: 2026/11/12 17:42:39 by vaperron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "helper_functions.h"

void	ft_0_pr(size_t pad, const char *str, int *cntr, char *arg_s)
{
	size_t	i;

	i = 0;
	if (arg_s[0] == '-')
	{
		write(1, "-", 1);
		cntr[1]++;
	}
	if (pad > ft_strlen(arg_s))
	{
		pad = pad - ft_strlen(arg_s);
		cntr[1] = cntr[1] + pad;
		while (i++ < pad)
			write(1, "0", 1);
	}
	if (arg_s[0] == '-')
		ft_printer(arg_s + 1, cntr, str);
	else
		ft_printer(arg_s, cntr, str);
}
