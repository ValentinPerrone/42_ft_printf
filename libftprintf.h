/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaperron <vaperron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 00:36:52 by vaperron          #+#    #+#             */
/*   Updated: 2026/10/28 15:03:57 by vaperron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

int		arg_number(char const *string);
void	*ft_calloc(size_t nmemb, size_t size);
char	*hextoa(unsigned int long long num);