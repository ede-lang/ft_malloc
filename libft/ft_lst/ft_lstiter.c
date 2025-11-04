/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-lang <ede-lang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 09:44:16 by ede-lang          #+#    #+#             */
/*   Updated: 2024/03/12 13:17:49 by ede-lang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/**
 * @brief apply a function to each content of a list.
 *
 * @param lst list
 * @param f function to apply
 */
void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (lst && (*f))
	{
		while (lst)
		{
			f(lst->content);
			lst = lst->next;
		}
	}
}
