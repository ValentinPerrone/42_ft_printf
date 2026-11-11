/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_functions.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaperron <vaperron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 22:34:14 by vaperron          #+#    #+#             */
/*   Updated: 2026/11/11 23:18:14 by vaperron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ======================== other headers ======================== //
#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>

// ====================== created functions ====================== //

int		ft_atoi(const char *nptr);
int		ft_print_char(char c);
int		ft_isalpha(int i);
int		ft_isdigit(int i);
size_t	ft_strlen(const char *s);
char	*ft_voidtoa(unsigned long long num, char c);
char	*ft_hextoa(unsigned long long num);
char	*ft_strchr(const char *s, int c);
char	*ft_toupper_string(char *string);
char	*ft_utoa(unsigned int n);
char	*ft_itoa(int n);
void	ft_bzero(void *s, size_t n);
