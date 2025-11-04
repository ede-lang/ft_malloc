/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-lang <ede-lang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 13:33:06 by ede-lang          #+#    #+#             */
/*   Updated: 2024/03/12 11:36:44 by ede-lang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief verify is char is an ascii value (0~127)
 *
 * @param ch char to test
 * @return int
 */
int	ft_isascii(int ch)
{
	if (ch >= 0 && ch <= 127)
		return (1);
	else
		return (0);
}
