/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-lang <ede-lang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 09:12:21 by ede-lang          #+#    #+#             */
/*   Updated: 2024/03/12 13:49:00 by ede-lang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/**
 * @brief print a char on the standard output
 *
 * @param val char to print
 * @return int return 1
 */
int	ft_putchar(int val)
{
	return (write(1, (char *)&val, 1));
}
