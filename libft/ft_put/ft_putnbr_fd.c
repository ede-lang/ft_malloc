/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-lang <ede-lang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 12:09:49 by ede-lang          #+#    #+#             */
/*   Updated: 2024/03/12 13:50:27 by ede-lang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/**
 * @brief print an int to a file descriptor
 *
 * @param n nb to print
 * @param fd file descriptor
 */
void	ft_putnbr_fd(int n, int fd)
{
	int	mod;
	int	div;

	mod = (n % 10);
	div = n / 10;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		mod = -mod;
		div = -div;
	}
	if (div)
		ft_putnbr_fd(div, fd);
	mod += 48;
	ft_putchar_fd(mod, fd);
}
