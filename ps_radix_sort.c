/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_radix.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toantune <toantune@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 19:03:37 by toantune          #+#    #+#             */
/*   Updated: 2024/04/29 21:34:59 by toantune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#define DEBUG
#include "push_swap.h"

int	stack_is_sorted(t_clist *stack)
{
	t_clist	*curr;

	curr = stack;
	while (1)
	{
		if ((curr->next->data < curr->data) && (curr->next != stack))
			return (0);
		curr = curr->next;
		if (curr == stack)
			break ;
	}
	return (1);
}

void	radix_sort(t_clist **stack_a, t_clist **stack_b, int size)
{
	int	n_bits;
	int	n_numbers;
	int	i;
	int	x;

	n_numbers = size;
	n_bits = 0;
	while ((n_numbers >> n_bits) != 0)
		n_bits++;
	i = 0;
	while (i < n_bits && stack_is_sorted(*stack_a) == 0)
	{
		x = 0;
		while (x < size && *stack_a)
		{
			if ((((*stack_a)->index >> i) & 1) == 1)
				ra(stack_a);
			else
				pb(stack_a, stack_b);
			x++;
		}
		while (*stack_b)
			pa(stack_a, stack_b);
		i++;
	}
}
