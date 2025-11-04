/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-lang <ede-lang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 13:24:09 by ede-lang          #+#    #+#             */
/*   Updated: 2024/03/12 11:48:50 by ede-lang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief convert [a~z] to [A~z] else return original value
 *
 * @param c
 * @return int
 */
int	ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
		return (c - 32);
	else
		return (c);
}
