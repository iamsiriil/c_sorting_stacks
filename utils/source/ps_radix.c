/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_radix.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toantune <toantune@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 19:03:37 by toantune          #+#    #+#             */
/*   Updated: 2024/04/22 19:08:59 by toantune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	max_bit_position(t_clist *stack)
{
	int		max_val;
	int		bits;
	t_clist	*curr;

	max_val = 0;
	curr = stack;
	while (curr != NULL)
	{
		if (curr->data > max_val)
			max_val = curr->data;
		curr = curr->next;
	}
	bits = 0;
	while ((max_val >> bits) != 0)
		bits++;
	return (bits);
}

void	radix_sort(t_clist **stack_a, t_clist **stack_b)
{
	int	bits;
	int	bit;
	int	size;
	int	i;

	bits = max_bit_position(*stack_a);
	bit = 0;
	while (bit < bits)
	{
		size = count_nodes(*stack_a);
		i = 0;
		while (i < size)
		{
			if ((((*stack_a)->data >> bit) & 1) == 0)
				pb(stack_a, stack_b);
			else
				ra(stack_a, stack_b);
			i++;
		}
		while (*stack_b != NULL)
			pa(stack_a, stack_b);
		bit++;
	}
}
