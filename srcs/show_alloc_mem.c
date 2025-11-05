/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc_mem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-lang <ede-lang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 11:28:11 by ede-lang          #+#    #+#             */
/*   Updated: 2025/11/05 13:32:59 by ede-lang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

static void print_block_ex(t_block *block)
{
    void *start = (void *)(block + 1);
    void *end = (char *)start + block->size;

    ft_printf("  [%s] %p - %p : %u bytes\n",
           block->free ? "ft_free" : "USED",
           start,
           end,
           block->size);
}

void show_alloc_mem(void)
{
    // ft_printf("---------------------Show allocations-----------------------\n");

    pthread_mutex_lock(&g_malloc_mutex);

    t_zone *zone = g_zones;
    size_t total = 0;

    while (zone)
    {
        const char *label = (zone->type == TINY) ? "TINY" :
                            (zone->type == SMALL) ? "SMALL" : "LARGE";

        ft_printf("%s : %p\n", label, zone);

        t_block *block = zone->blocks;
        while (block)
        {
            if (!block->free)
            {
                void *start = (void *)(block + 1);
                void *end = (char *)start + block->size;
                ft_printf("%p - %p : %u bytes\n", start, end, block->size);
                total += block->size;
            }
            block = block->next;
        }

        zone = zone->next;
    }

    ft_printf("Total : %u bytes\n", total);

    pthread_mutex_unlock(&g_malloc_mutex);
}


void show_alloc_mem_ex(void)
{
    // ft_printf("---------------------Show allocations EX-----------------------\n");
    pthread_mutex_lock(&g_malloc_mutex);

    t_zone *zone = g_zones;
    size_t total_used = 0;
    size_t total_ft_free = 0;

    while (zone)
    {
        const char *label = (zone->type == TINY) ? "TINY" :
                            (zone->type == SMALL) ? "SMALL" : "LARGE";

        ft_printf("%s ZONE @ %p | total zone size: %u bytes\n", label, zone, zone->size);

        t_block *block = zone->blocks;
        while (block)
        {
            print_block_ex(block);

            if (block->free)
                total_ft_free += block->size;
            else
                total_used += block->size;

            block = block->next;
        }

        zone = zone->next;
    }

    ft_printf("TOTAL USED : %u bytes\n", total_used);
    ft_printf("TOTAL ft_free : %u bytes\n", total_ft_free);

    pthread_mutex_unlock(&g_malloc_mutex);
}