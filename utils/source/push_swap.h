/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toantune <toantune@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 15:20:34 by toantune          #+#    #+#             */
/*   Updated: 2024/04/22 19:12:21 by toantune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "libft.h"

typedef struct s_clist
{
	int				data;
	struct s_clist	*next;
	struct s_clist	*prev;
}	t_clist;

// Clist
t_clist	*create_clist_node(int data);
void	push_clist(t_clist **stack, t_clist *node);
t_clist	*pop_clist(t_clist **stack);
void	free_clist(t_clist *stack);

// Operations
void	pa(t_clist **stack_a, t_clist **stack_b);
void	pb(t_clist **stack_a, t_clist **stack_b);

void	swap(t_clist **stack);
void	sa(t_clist **stack_a, t_clist **stack_b);
void	sb(t_clist **stack_a, t_clist **stack_b);
void	ss(t_clist **stack_a, t_clist **stack_b);

void	ra(t_clist **stack_a, t_clist **stack_b);
void	rb(t_clist **stack_a, t_clist **stack_b);
void	rr(t_clist **stack_a, t_clist **stack_b);

void	rra(t_clist **stack_a, t_clist **stack_b);
void	rrb(t_clist **stack_a, t_clist **stack_b);
void	rrr(t_clist **stack_a, t_clist **stack_b);

// Radix
int		max_bit_position(t_clist *stack);
void	radix_sort(t_clist **stack_a, t_clist **stack_b);

#endif
