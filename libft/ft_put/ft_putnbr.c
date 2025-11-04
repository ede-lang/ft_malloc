/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-lang <ede-lang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 09:26:35 by ede-lang          #+#    #+#             */
/*   Updated: 2024/03/12 13:53:26 by ede-lang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/**
 * @brief print a number on the standard output
 *
 */
int	ft_putnbr(long long nbr)
{
	int			count;
	int			digit;
	long long	rest;

	count = 0;
	digit = 0;
	rest = 0;
	if (nbr < 0)
	{
		nbr = -nbr;
		count += ft_putchar('-');
	}
	if (nbr > 9)
	{
		digit = nbr % 10;
		rest = nbr / 10;
		count += ft_putnbr(rest);
		count += ft_putchar(digit + '0');
	}
	else
		count += ft_putchar(nbr + '0');
	return (count);
}
