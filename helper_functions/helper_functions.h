/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaperron <vaperron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 22:45:39 by vaperron          #+#    #+#             */
/*   Updated: 2026/11/12 17:23:25 by vaperron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ======================== other headers ======================== //
#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include "../libft_functions/libft_functions.h"

// ====================== created functions ====================== //
int		ft_0_padd(size_t padding, const char *str, int *cntr, va_list list);
int		ft_l_just(int padding, const char *str, int *cntr, va_list list);
int		ft_flag_checker(const char *string, int *counter, va_list list);
int		ft_printer(char *str, int *cntr, const char *main_str);
int		ft_hash_flag(const char *str, int *cntr, va_list list);
int		ft_null_check(char *str, int *cntr);
char	*ft_caster(char c, va_list list);
char	*ft_c_assigner(va_list list);
void	ft_dot(size_t precision, const char *str, int *cntr, va_list list);
void	ft_sp_al(size_t padding, const char *str, int *cntr, va_list list);
void	ft_pl_al(size_t padding, const char *str, int *cntr, va_list list);
void	ft_0_pr(size_t pad, const char *str, int *cntr, char *arg_s);