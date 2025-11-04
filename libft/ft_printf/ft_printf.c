/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-lang <ede-lang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 11:24:18 by ede-lang          #+#    #+#             */
/*   Updated: 2024/03/12 13:46:06 by ede-lang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static int	formatprint(char spec, va_list ap)
{
	int	count;

	count = 0;
	if (spec == 'c')
		count = ft_putchar(va_arg(ap, int));
	else if (spec == 's')
		count = ft_putstr(va_arg(ap, char *));
	else if (spec == 'p')
		count = ft_putadr(va_arg(ap, unsigned long));
	else if (spec == 'd')
		count = ft_putnbr(va_arg(ap, int));
	else if (spec == 'i')
		count = ft_putnbr(va_arg(ap, int));
	else if (spec == 'u')
		count = ft_putunbr(va_arg(ap, unsigned int));
	else if (spec == 'x')
		count = ft_putnbr_hexa(va_arg(ap, unsigned int), 0);
	else if (spec == 'X')
		count = ft_putnbr_hexa(va_arg(ap, unsigned int), 1);
	else
		count = write(1, &spec, 1);
	return (count);
}

/**
 * @brief Put a complex set of string on the standard output
 *
 * @param format string format to print, man 3 printf for more info
 * @param ...
 * @return int
 */
int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		count;
	int		i;

	count = 0;
	i = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			count += formatprint(format[i], ap);
		}
		else
			count += write(1, &format[i], 1);
		i++;
	}
	return (count);
}
