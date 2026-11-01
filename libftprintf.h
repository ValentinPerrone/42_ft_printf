/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaperron <vaperron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 00:36:52 by vaperron          #+#    #+#             */
/*   Updated: 2026/11/01 02:52:13 by vaperron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

int		ft_terminal_write(char const *string, char stopper_char, int character_ct);
int		ft_flag_checker(char *string, int string_pos, va_list list);
int		ft_arg_number(char const *string);
int		ft_caster(char c, va_list list);
int		ft_atoi(const char *nptr);
int		ft_print_char(char c);
int		ft_abs_val(int num);
int		ft_isalpha(int i);
int		ft_isdigit(int i);
char	*ft_toupper_string(char *string);
char	*ft_voidtoa(unsigned long num);
char	*ft_hextoa(unsigned long num);
char	*ft_utoa(unsigned int n);
char	*ft_itoa(int n);
void	*ft_calloc(size_t nmemb, size_t size);