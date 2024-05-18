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

#include "push_swap.h"

void    sort_stack_3(t_clist **stack)
{
    int max;
    int min;

    max = 2;
    min = 0;
    if ((*stack)->index == min && (*stack)->next->index == max)
    {
        sa(stack);
        ra(stack);
    }
    else if ((*stack)->index == max && (*stack)->next->index == min)
        ra(stack);
    else if ((*stack)->index == max && (*stack)->next->index != min)
    {
        sa(stack);
        ra(stack);
    }
    else if (((*stack)->index != max && (*stack)->index != min) && ((*stack)->next->index == min))
        sa(stack);
    else if (((*stack)->index != max && (*stack)->index != min) && ((*stack)->next->index == max))
        rra(stack);
}

void    small_sort(t_clist **stack_a, t_clist **stack_b, int size)
{
    (void)stack_b; 
    if (size == 2)
        sa(stack_a);
    else if (size == 3)
        sort_stack_3(stack_a);
}