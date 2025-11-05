/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-lang <ede-lang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 14:51:28 by ede-lang          #+#    #+#             */
/*   Updated: 2025/11/05 13:33:09 by ede-lang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

void *malloc(size_t size)
{
    if (is_debug_mode())
        ft_printf("[MALLOC_DEBUG] Allocating %u bytes\n", size);

    void *ptr;

    pthread_mutex_lock(&g_malloc_mutex);

    if (size == 0)
    {
        pthread_mutex_unlock(&g_malloc_mutex);
        return NULL;
    }

    size = ALIGN16(size);

    if (size <= TINY_MAX)
        ptr = allocate_in_zone(TINY, size);
    else if (size <= SMALL_MAX)
        ptr = allocate_in_zone(SMALL, size);
    else
        ptr = allocate_large(size);

    pthread_mutex_unlock(&g_malloc_mutex);
    return ptr;
}