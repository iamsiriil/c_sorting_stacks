/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_opr_swap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toantune <toantune@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 19:00:34 by toantune          #+#    #+#             */
/*   Updated: 2024/04/22 19:01:59 by toantune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_clist **stack)
{
	t_clist	*first;
	t_clist	*second;

	if (*stack && (*stack)->next != *stack)
	{
		*first = *stack;
		*second = first->next;
		first->next = second->next;
		second->next->prev = first;
		second->next = first;
		second->prev = first->prev;
		first->prev->next = second;
		first->prev = second;
		*stack = second;
	}
}

void	sa(t_clist **stack_a, t_clist **stack_b)
{
	swap(stack_a);
	ft_printf("sa\n");
}

void	sb(t_clist **stack_a, t_clist **stack_b)
{
	swap(stack_b);
	ft_printf("sb\n");
}

void	ss(t_clist **stack_a, t_clist **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	ft_printf("ss\n");
}
