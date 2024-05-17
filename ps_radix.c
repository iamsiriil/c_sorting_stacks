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

static int	stack_is_sorted(t_clist *stack)
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

// static void segment_is_sorted(t_clist **stack_a, int iter)
// {
// 	t_clist	*start;
// 	int		counter;

// 	start = (*stack_a);
// 	counter = 0;
// 	while ((*stack_a) && ((*stack_a)->next != start))
// 	{
// 		if (((*stack_a)->index == ((*stack_a)->next->index - 1)) && 
// 			(((*stack_a)->index >> iter) & 1) == 0)
// 			counter++;
// 		else
// 			return ;
// 		(*stack_a) = (*stack_a)->next;
// 	}
// 	while (counter--)
// 		ra(stack_a);
// }

// static void	swap_optimize(t_clist **stack_a, t_clist **stack_b, int iter)
// {
// 	if (((*stack_a)->next->index == ((*stack_a)->index - 1)) && 
// 		(((*stack_a)->index >> iter) & 1) == 0)
// 		sa(stack_a);
// 	else if ((*stack_b) && (*stack_b)->next != (*stack_b) &&
// 		((*stack_b)->index == ((*stack_b)->next->index - 1)) && 
// 		(((*stack_b)->index >> iter) & 1) == 0)
// 		sb(stack_b);
// }

void	radix_sort(t_clist **stack_a, t_clist **stack_b, int argc)
{
	int	n_bits;
	int	n_numbers;
	int	i;
	int	x;

	n_numbers = argc - 1;
	n_bits = 0;
	while ((n_numbers >> n_bits) != 0)
		n_bits++;
	i = 0;
	while (i < n_bits && stack_is_sorted(*stack_a) == 0)
	{
		
		x = 0;
		while (x < argc - 1 && *stack_a)
		{
			
			// if ((((*stack_a)->index >> i) & 1) == 0)
			// {
				
				//swap_optimize(stack_a, stack_b, i);
				//segment_is_sorted(stack_a, i);
			// }		
			// else
			// {
				if ((((*stack_a)->index >> i) & 1) == 1)
					ra(stack_a);
				else
					pb(stack_a, stack_b);
			//}
			x++;
		}

		while (*stack_b)
			pa(stack_a, stack_b);
		i++;
	}
}
