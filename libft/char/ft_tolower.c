/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-lang <ede-lang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 13:36:10 by ede-lang          #+#    #+#             */
/*   Updated: 2024/03/12 11:48:13 by ede-lang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief convert a [A~Z] to [a~z] else return original value
 *
 * @param c
 * @return int
 */
int	ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
		return (c + 32);
	else
		return (c);
}
