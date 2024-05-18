/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_opr_push.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toantune <toantune@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 18:52:43 by toantune          #+#    #+#             */
/*   Updated: 2024/04/22 18:55:03 by toantune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_clist **stack_a, t_clist **stack_b)
{
	t_clist	*node;

	*node = pop_clist(stack_b);
	if (node)
		push_clist(stack_a, node);
	ft_printf("pa\n");
}

void	pb(t_clist **stack_a, t_clist **stack_b)
{
	t_clist	*node;

	*node = pop_clist(stack_a);
	if (node)
		push_clist(stack_b, node);
	ft_printf("pb\n");
}
