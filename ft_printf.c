/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaperron <vaperron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 00:39:47 by vaperron          #+#    #+#             */
/*   Updated: 2026/10/28 15:59:42 by vaperron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*caster(char c, va_list list)
{
	char	*substring;
	if (c == 'c')
		substring = va_arg(list, char *);
	else if (c == 's')
		substring = va_arg(list, char *);
	else if (c == 'p')
		substring = hextoa(va_arg(list, void *));
	/*else if (c == 'd')
		write
	else if (c == 'i')
		write
	else if (c == 'u')
		write
	else if (c == 'x')
		write
	else if (c == 'x')
		write
	else if (c == '%')
		write*/
	return (substring);
}

int	ft_printf(char const *string, ...)
{
	int		i;
	int		j;
	int		k;
	int		l;
	char	*substring;
	va_list	list;

	i = 0;
	l = 0;
	k = arg_number(string);
	va_start(list, string);
	while(string[l])
	{
		j = 0;
		while(string[l])
		{
			if (string[l] == '%')
			break;
			write(1,&string[l], 1);
			l++;
		}
		if (string[l] == '%')
			l = l + 2;
		if (i < k)
		{
			substring = caster(string[l - 1], list);
			while(substring[j])
			{
				write(1,&substring[j], 1);
				j++;
			}
			i++;
		}
	}
	va_end(list);
}

int main(void)
{
	char *test = " test1 ";
	int num[1] = {42};
	//ft_printf("hola%s%s%p%sholaaaaaaa\n", " mundo", test, &num, " test2 ");
	printf("hola%d%p%smundo\n", 356.4652467, &num, " test2 ");
	return (0);
}
