/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_opr_swap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toantune <toantune@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 19:00:34 by toantune          #+#    #+#             */
/*   Updated: 2024/04/24 08:19:17 by toantune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_clist **stack_a)
{
	swap(stack_a);
	ft_printf("sa\n");
}

void	sb(t_clist **stack_b)
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
