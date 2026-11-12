/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaperron <vaperron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 00:36:52 by vaperron          #+#    #+#             */
/*   Updated: 2026/11/12 17:41:51 by vaperron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ======================== other headers ======================== //
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "libft_functions/libft_functions.h"
#include "helper_functions/helper_functions.h"

// ====================== created functions ====================== //
int		ft_twrite(char const *string, char st_char, int *cntr, int main);
int		ft_flag_checker(const char *s, int *c, va_list list);
int		ft_printf(char const *string, ...);
int		ft_arg_number(char const *string);
int		ft_abs_val(int num);