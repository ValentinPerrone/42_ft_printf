/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_checker.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaperron <vaperron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 02:43:50 by vaperron          #+#    #+#             */
/*   Updated: 2026/11/11 21:55:57 by vaperron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	zero_printing(const char *string, char *arg_string, int *counter, size_t i, size_t padding)
{
	if (arg_string[0] == '-')
	{
		write(1, "-", 1);
		counter[1]++;
	}
	if (padding > ft_strlen(arg_string))
	{
		padding = padding - ft_strlen(arg_string);
		counter[1] = counter[1] + padding;
		while(i++ < padding)
			write(1, "0", 1);
	}
	if (arg_string[0] == '-')
		ft_printer(arg_string + 1, counter, string);
	else
		ft_printer(arg_string, counter, string);
}

static int	dot_precision(size_t precision, const char *string, int *counter, va_list list)
{
	size_t	i;
	char	*arg_string;

	i = 0;
	while (ft_isalpha(string[counter[0]]) == 0)
		counter[0]++;
	arg_string = ft_caster(string[counter[0]], list);
	if (string[counter[0]] == 's')
	{
		while(i++ < precision && arg_string[i - 1])
		{
			write(1, &arg_string[i - 1], 1);
			counter[1]++;
		}
	}
	else
	{
		if (arg_string[0] == '-')
			zero_printing(string, arg_string, counter, i, precision + 1);
		else
			zero_printing(string, arg_string, counter, i, precision);
	}
	if (ft_strchr("cpdiuxX", string[counter[0]]) != NULL)
			free(arg_string);
	counter[0]++;
	return(counter[1]);
}

static int	hash_flag(const char *string, int *counter, va_list list)
{
	char	*arg_string;
	
	while (ft_isalpha(string[counter[0]]) == 0)
		counter[0]++;
	arg_string = ft_caster(string[counter[0]], list);
	if(arg_string[0] != '0')
	{
		if(string[counter[0]] == 'x' )
			write(1, "0x", 2);
		else if(string[counter[0]] == 'X')
			write(1, "0X", 2);
		counter[1] = counter[1] + 2;
	}
	ft_printer(arg_string, counter, string);
	if (ft_strchr("cpdiuxX", string[counter[0]]) != NULL)
			free(arg_string);
	counter[0]++;
	return(counter[1]);
}

static int	zero_padding(size_t padding, const char *string, int *counter, va_list list)
{
	size_t	i;
	char	*arg_string;

	i = 0;
	while (ft_isalpha(string[counter[0]]) == 0)
		counter[0]++;
	arg_string = ft_caster(string[counter[0]], list);
	zero_printing(string, arg_string, counter, i, padding);
	if (ft_strchr("cpdiuxX", string[counter[0]]) != NULL)
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
	character_ct = ft_printer(arg_string, counter, string);
	if (ft_strchr("cpdiuxX", string[counter[0]]) != NULL)
			free(arg_string);
	counter[0]++;
	if (padding >= character_ct)
	{
		padding = padding - character_ct;
		if (padding != 0)
			counter[1] = counter[1] + padding;
		while(i++ < padding)
			write(1, " ", 1);
	}
	return(counter[1]);
}

static int	flag_override(const char *string, int *counter, char character)
{
	int	i;

	i = 0;
	while(ft_isalpha(string[counter[0] + i]) == 0)
	{
		if(string[counter[0] + i] == character)
			break;
		i++;
	}
	if(string[counter[0] + i] == character)
	{
		counter[0] = counter[0] + (i - 1);
		return(1);
	}
	return(0);
}
/**/
void	plus_alignment(size_t padding, const char *string, int *counter, va_list list)
{
	char	*arg_string;

	counter[0]++;
	while (ft_isalpha(string[counter[0]]) == 0)
		counter[0]++;
	arg_string = ft_caster(string[counter[0]] , list);
	if (padding > ft_strlen(arg_string))
	{
		if(arg_string[0] != '-')
			padding--;
		padding = padding - ft_strlen(arg_string);
		if (padding != 0)
			counter[1] = counter[1] + padding;
		while(padding-- > 0)
			write(1, " ", 1);
	}
	if(arg_string[0] != '-')
	{
		write(1, "+", 1);
		counter[1]++;
	}
	if(ft_strlen(arg_string) != 0)
		ft_printer(arg_string, counter, string);
	if (ft_strchr("cpdiuxX", string[counter[0]]) != NULL)
		free(arg_string);
	counter[0]++;
}

void	space_alignment(size_t padding, const char *string, int *counter, va_list list)
{
	char	*arg_string;

	counter[0]++;
	while (ft_isalpha(string[counter[0]]) == 0)
		counter[0]++;
	arg_string = ft_caster(string[counter[0]] , list);
	if(ft_strlen(arg_string) != 0 && string[counter[0]] != 's' && arg_string[0] != '-')
	{
		write(1, " ", 1);
		counter[1]++;
	}
	if (padding > ft_strlen(arg_string))
	{
		padding = padding - ft_strlen(arg_string);
		if (padding != 0)
			counter[1] = counter[1] + padding;
		while(padding-- > 0)
			write(1, " ", 1);
	}
	if(ft_strlen(arg_string) != 0)
		ft_printer(arg_string, counter, string);
	if (ft_strchr("cpdiuxX", string[counter[0]]) != NULL)
		free(arg_string);
	counter[0]++;
}

int	ft_flag_checker(const char *string, int *counter, va_list list)
{
	char *arg_string;
	if (string[counter[0] + 1] == '#')
		hash_flag(string, counter, list);
	else if (string[counter[0] + 1] == ' ' && flag_override(string, counter, '+') == 0)
		space_alignment(ft_atoi(&string[counter[0] + 1]), string, counter, list);
	else if (string[counter[0] + 1] == '+')
		plus_alignment(ft_atoi(&string[counter[0] + 1]), string, counter, list);
	else if (string[counter[0] + 1] == '-' || (ft_isdigit(string[counter[0] + 1]) == 1 && string[counter[0] + 1] != '0'))
		left_justification(ft_atoi(&string[counter[0] + 1]), string, counter, list);
	else if (string[counter[0] + 1] == '0' && flag_override(string, counter, '.') == 0)
		zero_padding(ft_atoi(&string[counter[0] + 2]), string, counter, list);
	else if (string[counter[0] + 1] == '.')
		dot_precision(ft_atoi(&string[counter[0] + 2]), string, counter, list);
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