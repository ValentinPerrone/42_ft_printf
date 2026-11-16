/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaperron <vaperron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 00:36:52 by vaperron          #+#    #+#             */
/*   Updated: 2026/11/16 20:28:10 by vaperron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ======================== other headers ======================== //
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "libft_functions/libft_functions.h"
#include "ft_printf_bonus/ft_printf_bonus.h"

// ====================== created functions ====================== //
int		ft_twrite(char const *string, char st_char, int *cntr, int main);
int		ft_printer(char *string, int *counter, const char *main_string);
int		ft_flag_checker(const char *str, int *cntr, va_list list);
int		ft_null_check(char *string, int *counter);
int		ft_arg_number(char const *string);
int		ft_abs_val(int num);
char	*ft_caster(char c, va_list list);