/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_opr_rev_rotation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toantune <toantune@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 18:58:36 by toantune          #+#    #+#             */
/*   Updated: 2024/04/24 20:24:41 by toantune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_clist **stack_a)
{
	if (stack_a && *stack_a && (*stack_a)->next != *stack_a)
		*stack_a = (*stack_a)->prev;
	ft_printf("rra\n");
}

void	rrb(t_clist **stack_b)
{
	if (stack_b && *stack_b && (*stack_b)->next != *stack_b)
		*stack_b = (*stack_b)->prev;
	ft_printf("rrb\n");
}

void	rrr(t_clist **stack_a, t_clist **stack_b)
{
	if (stack_a && *stack_a && (*stack_a)->next != *stack_a)
		*stack_a = (*stack_a)->prev;
	if (stack_b && *stack_b && (*stack_b)->next != *stack_b)
		*stack_b = (*stack_b)->prev;
	ft_printf("rrr\n");
}
