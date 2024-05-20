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

void	reverse_rotation(t_clist **stack)
{
	if (stack && (*stack) && (*stack)->prev != (*stack))
		(*stack) = (*stack)->prev;
}

void	rra(t_clist **stack_a)
{
	reverse_rotation(stack_a);
	ft_printf("rra\n");
}

void	rrb(t_clist **stack_b)
{
	reverse_rotation(stack_b);
	ft_printf("rrb\n");
}

void	rrr(t_clist **stack_a, t_clist **stack_b)
{
	reverse_rotation(stack_a);
	reverse_rotation(stack_b);
	ft_printf("rrr\n");
}
