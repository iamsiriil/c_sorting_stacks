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

void	rotation(t_clist **stack)
{
	if (stack && *stack && (*stack)->next != (*stack))
		(*stack) = (*stack)->next;
}

void	ra(t_clist **stack_a)
{
	rotation(stack_a);
	ft_printf("ra\n");
}

void	rb(t_clist **stack_b)
{
	rotation(stack_b);
	ft_printf("rb\n");
}

void	rr(t_clist **stack_a, t_clist **stack_b)
{
	rotation(stack_a);
	rotation(stack_b);
	ft_printf("rr\n");
}
