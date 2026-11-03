/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_checker.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaperron <vaperron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 02:43:50 by vaperron          #+#    #+#             */
/*   Updated: 2026/11/03 22:32:40 by vaperron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	zero_padding(size_t padding, const char *string, int *counter, va_list list)
{
	size_t	i;
	char	*arg_string;

	i = 0;
	while (ft_isalpha(string[counter[0]]) == 0)
		counter[0]++;
	arg_string = ft_caster(string[counter[0]], list);
	if (padding > ft_strlen(arg_string))
	{
		padding = padding - ft_strlen(arg_string);
		counter[1] = counter[1] + padding;
		while(i++ < padding)
			write(1, "0", 1);
	}
	else
		counter[1] = counter[1] + ft_strlen(arg_string);
	ft_printer(arg_string, counter);
	if (ft_strchr("pdiuxX", string[counter[0]]) != NULL)
			free(arg_string);
	counter[0]++;
	return(counter[1]);
}
static int	left_justification(int padding, const char *string, int *counter, va_list list)
{
	int	i;
	int	character_ct;
	char	*arg_string;

	i = 0;
	while (ft_isalpha(string[counter[0]]) == 0)
		counter[0]++;
	arg_string = ft_caster(string[counter[0]], list);
	character_ct = ft_printer(arg_string, counter);
	if (ft_strchr("pdiuxX", string[counter[0]]) != NULL)
			free(arg_string);
	counter[0]++;
	if (padding > character_ct)
	{
		padding = padding - character_ct;
		counter[1] = counter[1] + padding;
		while(i++ < padding)
			write(1, " ", 1);
	}
	else
		counter[1] = counter[1] + character_ct;
	return(counter[1]);
}

int	point_flag(char *string, int *counter)
{
	int	i;

	i = 0;
	while(ft_isalpha(string[counter[0] + i]) == 0)
	{
		if(string[counter[0] + i] == '.')
			break;
		i++;
	}
	if(string[counter[0] + i] == '.')
	{
		counter[0] = counter[0] + (i - 1);
		return(1);
	}
	return(0);
	
}

int	ft_flag_checker(const char *string, int *counter, va_list list)
{
	char *arg_string;
	if (string[counter[0] + 1] == '#')
		write(1, "h", 1);//do something
	else if (string[counter[0] + 1] == '+')
		write(1, "h", 1);//do something
	else if (string[counter[0] + 1] == ' ')
		write(1, "h", 1);//do something
	else if (string[counter[0] + 1] == '-')
		left_justification(ft_atoi(&string[counter[0] + 2]), string, counter, list);
	else if (string[counter[0] + 1] == '0' && point_flag(string, counter) == 0)
		zero_padding(ft_atoi(&string[counter[0] + 2]), string, counter, list);
	else if (string[counter[0] + 1] == '.')
		zero_padding(ft_atoi(&string[counter[0] + 2]), string, counter, list);
	else
	{
		arg_string = ft_caster(string[counter[0] + 1], list);
		ft_printer(arg_string, counter);
	if (ft_strchr("pdiuxX", string[counter[0] + 1]) != NULL)
			free(arg_string);
		counter[0] = counter[0] + 2;
	}
	return(counter[1]);
}