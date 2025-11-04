/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-lang <ede-lang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 09:26:35 by ede-lang          #+#    #+#             */
/*   Updated: 2024/03/12 13:55:42 by ede-lang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/**
 * @brief print unsigned int on the standard output
 *
 * @param nbr number to print
 * @return int number of char printed
 */
static int	publishbase(unsigned long long nbr)
{
	int	digit;
	int	count;

	count = 0;
	if (nbr > 9)
	{
		digit = nbr % 10;
		count += publishbase(nbr / 10);
		count += ft_putchar(digit + '0');
	}
	else
		count += ft_putchar(nbr + '0');
	return (count);
}

int	ft_putunbr(unsigned long long nbr)
{
	int	count;

	count = 0;
	count += publishbase(nbr);
	return (count);
}
