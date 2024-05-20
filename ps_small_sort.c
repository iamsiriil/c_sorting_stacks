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
    return (count);
}

void    sort_stack_4(t_clist **stack_a, t_clist ** stack_b)
{
    int     count;
    int     i;

    i = 0;
    if ((*stack_a)->index != 0)
    {
        count = get_nbr_position((*stack_a), 0);
        if (count <= 2)
        {
            while (i++ < count)
                ra(stack_a);
        }
        else
        {
            count = 4 - count;
            while (i++ < count)
                rra(stack_a);
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