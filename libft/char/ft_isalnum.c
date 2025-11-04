/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-lang <ede-lang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:07:38 by ede-lang          #+#    #+#             */
/*   Updated: 2024/03/12 11:38:23 by ede-lang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief verify if char is [A~Z] [a~z] [0~9]
 *
 * @param ch char to test
 * @return int
 */
int	ft_isalnum(int ch)
{
	if ((ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122))
		return (1);
	else if (ch >= 48 && ch <= 57)
		return (1);
	else
		return (0);
}
