/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaperron <vaperron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 22:45:39 by vaperron          #+#    #+#             */
/*   Updated: 2026/11/11 23:18:18 by vaperron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ======================== other headers ======================== //
#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>

// ====================== created functions ====================== //
int		ft_dot_precision(size_t precision, const char *string, int *counter, va_list list);
int		ft_left_justification(int padding, const char *string, int *counter, va_list list);
int		ft_zero_padding(size_t padding, const char *string, int *counter, va_list list);
int		ft_flag_override(const char *string, int *counter, char character);
int		ft_printer(char *string, int *counter, const char *main_string);
int		ft_hash_flag(const char *string, int *counter, va_list list);
int		ft_null_check(char *string, int *counter);
char	*ft_c_assigner(va_list list);
void	ft_zero_printing(const char *string, char *arg_string, int *counter, size_t i, size_t padding);
void	ft_space_alignment(size_t padding, const char *string, int *counter, va_list list);
void	ft_plus_alignment(size_t padding, const char *string, int *counter, va_list list);
