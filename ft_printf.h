/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaperron <vaperron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 00:36:52 by vaperron          #+#    #+#             */
/*   Updated: 2026/11/19 15:33:22 by vaperron         ###   ########.fr       */
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
int		ft_null_check(char *string, int *counter);
int		ft_arg_number(char const *string);
int		ft_abs_val(int num);
char	*ft_c_assigner(va_list list);
char	*ft_caster(char c, va_list list);