/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaperron <vaperron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 00:36:52 by vaperron          #+#    #+#             */
/*   Updated: 2026/10/29 21:54:13 by vaperron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

int		ft_arg_number(char const *string);
int		ft_terminal_write(char *string, char stopper_char, int current_pos);
int     ft_abs_val(int num);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_toupper_string(char *string);
char	*ft_hextoa(unsigned long num);
char	*ft_itoa(int n);
