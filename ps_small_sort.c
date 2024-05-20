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

void    sort_stack_4(t_clist **stack_a, t_clist ** stack_b)
{
    LOG_MESSAGE("function call\n");
    t_clist *curr;
    int     max;
    int     min;
    int     count;
    int     i;

    max = get_stck_max((*stack_a)) + 1;
    min = get_stck_min((*stack_a));
    LOG_MESSAGE("max = %d; min = %d\n", max, min);
    curr = (*stack_a);
    count = 0;
    //int iter = 1;
    if (curr->index != min)
    {    
        while (curr->index != min)
        {
            count++;
            curr = curr->next;
            LOG_MESSAGE("iter = %d; count = %d\n", iter++, count);
        }
        LOG_MESSAGE("count = %d\n", count);
        //iter = 1;
        if (count <= 2)
        {
            i = 0;
            while (i < count)
            {
                LOG_MESSAGE("condition 1 (count < 2): iter = %d; count = %d\n", iter++, count);
                ra(stack_a);
                i++;
            }
        }
        else
        {
            count = max - count;
            LOG_MESSAGE("max - count = %d\n", count);
            i = 0;
            while (i < count)
            {
                LOG_MESSAGE("condition 2 (else): iter = %d; count = %d\n", iter++, count);
                rra(stack_a);
                i++;
            }
        }
    }
    pb(stack_a, stack_b);
    sort_stack_3(stack_a);
    pa(stack_a, stack_b);
}

void    sort_stack_3(t_clist **stack)
{
    LOG_MESSAGE("function call\n");
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

void    small_sort(t_clist **stack_a, t_clist **stack_b, int size)
{
    (void)stack_b; 
    if (size == 2)
        sa(stack_a);
    else if (size == 3)
        sort_stack_3(stack_a);
    else if (size == 4)
        sort_stack_4(stack_a, stack_b);
}