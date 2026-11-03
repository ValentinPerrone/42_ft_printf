/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaperron <vaperron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 00:36:52 by vaperron          #+#    #+#             */
/*   Updated: 2026/11/03 15:51:23 by vaperron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

int		ft_terminal_write(char const *string, char stopper_char, int *counter, int is_main_str);
int		ft_flag_checker(const char *string, int *counter, va_list list);
int		ft_caster(char c, int *counter, va_list list);
int		ft_arg_number(char const *string);
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
void	ft_bzero(void *s, size_t n);