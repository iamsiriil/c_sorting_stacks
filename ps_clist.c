/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_clist.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toantune <toantune@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 10:38:50 by toantune          #+#    #+#             */
/*   Updated: 2024/04/29 10:42:28 by toantune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#define DEBUG
#include "push_swap.h"

t_clist	*create_clist_node(int data, int idx)
{
	t_clist	*new_node;

	new_node = malloc(sizeof(t_clist));
	new_node->data = data;
	new_node->index = idx;
	new_node->next = new_node;
	new_node->prev = new_node;
	return (new_node);
}

void	push_clist(t_clist **stack, t_clist *node)
{
	if (!*stack)
		*stack = node;
	else
	{
		node->prev = (*stack)->prev;
		node->next = *stack;
		(*stack)->prev->next = node;
		(*stack)->prev = node;
	}
	*stack = node;
}

t_clist	*pop_clist(t_clist **stack)
{
	t_clist	*top;

	if (!*stack)
		return (NULL);
	top = *stack;
	if (top->next == top)
		*stack = NULL;
	else
	{
		top->prev->next = top->next;
		top->next->prev = top->prev;
		*stack = top->next;
	}
	top->prev = top;
	top->next = top;

	return (top);
}

void	free_clist(t_clist *stack)
{
	t_clist	*curr;
	t_clist	*next;
	t_clist	*last;

	if (stack == NULL)
		return ;
	curr = stack;
	next = NULL;
	last = stack->prev;
	last->next = NULL;
	while (curr != NULL)
	{
		next = curr->next;
		free(curr);
		curr = next;
	}
}

int	count_nodes(t_clist *stack)
{
	t_clist	*current;
	int		count;

	if (stack == NULL)
		return (0);
	count = 0;
	current = stack;
	while (1)
	{
		count++;
		current = current->next;
		if (current == stack)
			break ;
	}
	return (count);
}
