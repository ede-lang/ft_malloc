/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-lang <ede-lang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 16:53:32 by ede-lang          #+#    #+#             */
/*   Updated: 2024/03/12 11:30:41 by ede-lang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static int	getvalue(char c, int base)
{
	int	val;

	val = -1;
	c = ft_tolower(c);
	if (c >= '0' && c <= '9')
		val = c - 48;
	if (c >= 'a' && c <= 'z')
		val = c - 87;
	if (val >= base)
		val = -1;
	return (val);
}

/**
 * @brief take a number in a string and convert it in int
 *
 * @param str the string containing the number value
 * @param base le size of the base (ex: hexadecimal is 16)
 * @return int
 */
int	ft_atoi_base(char *str, int base)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	result = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	if (base == 16 && str[i] == '0' && str[i + 1] == 'x')
		i += 2;
	while (getvalue(str[i], base) != -1 && str[i])
	{
		result = result * base + getvalue(str[i], base);
		i++;
	}
	return (result * sign);
}
