/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_opr_rotation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toantune <toantune@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 18:56:43 by toantune          #+#    #+#             */
/*   Updated: 2024/04/24 20:23:36 by toantune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_clist **stack_a)
{
	if (stack_a && *stack_a && (*stack_a)->next != *stack_a)
		*stack_a = (*stack_a)->next;
	ft_printf("ra\n");
}

void	rb(t_clist **stack_b)
{
	if (stack_b && *stack_b && (*stack_b)->next != *stack_b)
		*stack_b = (*stack_b)->next;
	ft_printf("rb\n");
}

void	rr(t_clist **stack_a, t_clist **stack_b)
{
	if (stack_a && *stack_a && (*stack_a)->next != *stack_a)
		*stack_a = (*stack_a)->next;
	if (stack_b && *stack_b && (*stack_b)->next != *stack_b)
		*stack_b = (*stack_b)->next;
	ft_printf("rr\n");
}
