/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_opr_rev_rotation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toantune <toantune@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 18:58:36 by toantune          #+#    #+#             */
/*   Updated: 2024/04/22 18:59:43 by toantune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_clist **stack_a, t_clist **stack_b)
{
	if (stack_a && *stack_a && (*stack_a)->next != *stack_a)
		*stack_a = (*stack_a)->next;
	ft_printf("rra\n");
}

void	rrb(t_clist **stack_a, t_clist **stack_b)
{
	if (stack_b && *stack_b && (*stack_b)->next != *stack_b)
		*stack_b = (*stack_b)->next;
	ft_printf("rrb\n");
}

void	rrr(t_clist **stack_a, t_clist **stack_b)
{
	rra(stack_a, stack_b);
	rrb(stack_a, stack_b);
	ft_printf("rrr\n");
}
