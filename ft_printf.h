/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaperron <vaperron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 00:36:52 by vaperron          #+#    #+#             */
/*   Updated: 2026/11/12 17:22:21 by vaperron         ###   ########.fr       */
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
int		ft_printer(char *string, int *counter, const char *main_string);
int		ft_flag_override(const char *str, int *cntr, char character);
int		ft_arg_number(const char *string);
int		ft_atoi(const char *nptr);
int		ft_abs_val(int num);
int		ft_isalpha(int i);
int		ft_isdigit(int i);
size_t	ft_strlen(const char *s);
char	*ft_voidtoa(unsigned long long num, char c);
char	*ft_toupper_string(char *string);
char	*ft_strchr(const char *s, int c);
char	*ft_hextoa(unsigned long long num);
char	*ft_utoa(unsigned int n);
char	*ft_itoa(int n);
void	*ft_calloc(size_t nmemb, size_t size);
void	ft_bzero(void *s, size_t n);
