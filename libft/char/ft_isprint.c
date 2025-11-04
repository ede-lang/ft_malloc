/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-lang <ede-lang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 13:38:56 by ede-lang          #+#    #+#             */
/*   Updated: 2024/03/12 11:38:18 by ede-lang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief verify if the char is displayable [32~126]
 *
 * @param ch the char to test
 * @return int
 */
int	ft_isprint(int ch)
{
	if (ch >= 32 && ch <= 126)
		return (1);
	else
		return (0);
}
