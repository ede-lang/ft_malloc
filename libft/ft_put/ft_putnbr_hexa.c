/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-lang <ede-lang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 09:34:11 by ede-lang          #+#    #+#             */
/*   Updated: 2024/03/12 13:52:37 by ede-lang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	publishbase(unsigned long long nbr, char *base)
{
	unsigned long long	base_size;
	int					digit;
	int					count;

	count = 0;
	base_size = 16;
	if (nbr > base_size - 1)
	{
		digit = nbr % base_size;
		count += publishbase(nbr / base_size, base);
		count += ft_putchar(base[digit]);
	}
	else
		count += ft_putchar(base[nbr]);
	return (count);
}

/**
 * @brief put an int in hexadecimal format on the standard output
 *
 * @param nbr number to print
 * @param capital boolean, if true set letters to capital
 * @return int
 */
int	ft_putnbr_hexa(unsigned long long nbr, int capital)
{
	int	count;

	count = 0;
	if (capital)
		count += publishbase(nbr, "0123456789ABCDEF");
	else
		count += publishbase(nbr, "0123456789abcdef");
	return (count);
}
