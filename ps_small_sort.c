/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toantune <toantune@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 20:55:09 by toantune          #+#    #+#             */
/*   Updated: 2024/04/29 10:44:29 by toantune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#define DEBUG
#include "push_swap.h"
#include "test_push_swap.h"

void    sort_stack_3(t_clist **stack)
{
    //LOG_MESSAGE("function call\n");
    int max;
    int min;

    max = get_stck_max((*stack));
    min = get_stck_min((*stack));
    LOG_MESSAGE("max = %d, min = %d\n", max, min);
    if ((*stack)->index == min && (*stack)->next->index == max)
    {
        sa(stack);
        ra(stack);
    }
    else if ((*stack)->index == max && (*stack)->next->index == min)
        ra(stack);
    else if ((*stack)->index == max && (*stack)->prev->index == min)
    {
        ra(stack);
        sa(stack);
    }
    else if (((*stack)->index != max && (*stack)->index != min) &&
            ((*stack)->next->index == min))
        sa(stack);
    else if (((*stack)->index != max && (*stack)->index != min) &&
            ((*stack)->next->index == max))
        rra(stack);
}

int get_nbr_position(t_clist *stack, int nbr)
{
    t_clist *curr;
    int     count;

    count = 0;
    curr = stack;
    while (1)
    {
        if (curr->index != nbr)
            count++;
        curr = curr->next;
        if ((curr->index == nbr) || (curr == stack))
            break ;
    }
    LOG_MESSAGE("count = %d\n", count);
    return (count);
}

void    get_to_top(t_clist **stack_a, int size, int nbr)
{
    int break_size;
    int count;
    int i;

    break_size = size + (size % 1);
    LOG_MESSAGE("break size = %d\n", break_size);
    count = 0;
    i = 0;
    if ((*stack_a)->index != nbr)
    {
        count = get_nbr_position((*stack_a), nbr);
        if (count < (break_size / 2))
        {
            while (i++ < count)
                ra(stack_a);
        }
        else if (count >= (break_size / 2))
        {
            count = size - count;
            while (i++ < count)
                rra(stack_a);
        }
    }
}

void    select_sort(t_clist **stack_a, t_clist **stack_b, int size, int min)
{
    LOG_MESSAGE("function call for size %d\n", size);
    if (size > 3)
    {
        get_to_top(stack_a, size, min);
        pb(stack_a, stack_b);
        select_sort(stack_a, stack_b, size - 1, min + 1);
    }
    else 
    {
        sort_stack_3(stack_a);
        return ;
    }
    pa(stack_a, stack_b);
}