/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putadr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-lang <ede-lang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 09:56:47 by ede-lang          #+#    #+#             */
/*   Updated: 2024/03/12 13:47:05 by ede-lang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/**
 * @brief print an address to the standard output
 *
 * @param adr
 * @return int
 */
int	ft_putadr(unsigned long adr)
{
	int	count;

	count = 0;
	if (!adr)
		return (write(1, "(nil)", 5));
	count += ft_putstr("0x");
	count += ft_putnbr_hexa((unsigned long long)adr, 0);
	return (count);
}
