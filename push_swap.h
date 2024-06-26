/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toantune <toantune@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 15:20:34 by toantune          #+#    #+#             */
/*   Updated: 2024/04/29 10:49:38 by toantune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "./libft/libft.h"
# include <stdio.h>

typedef struct s_clist
{
	int				data;
	int				index;
	struct s_clist	*next;
	struct s_clist	*prev;
}	t_clist;

// Error
void		error(void **ptr, int size);

// Utils
long int	*convert_argv(int size, char **argv);
int			*map_index(long int *arr, int size);
int			get_argv_size(char **arg_vec);
int			get_stck_max(t_clist *stack);
int			get_stck_min(t_clist *stack);

// Parser
char		*create_arg_str(int argc, char **argv, size_t size);
char		**arg_parser(int argc, char **argv);

// Checker
void		check_char(char **arg_vec, int size);
void		check_dup(long int *arr_vec, int size);
void		check_int(long int *arr_vec, int size);
void		check_sort(long int *arr_vec, int size);
void		checker(char **arg_vec, int size, t_clist **stack_a);

// Clist
t_clist		*create_clist_node(int data, int idx);
void		push_clist(t_clist **stack, t_clist *node);
t_clist		*pop_clist(t_clist **stack);
void		free_clist(t_clist *stack);
int			count_nodes(t_clist *stack);

// Operations
void		pa(t_clist **stack_a, t_clist **stack_b);
void		pb(t_clist **stack_a, t_clist **stack_b);

void		swap(t_clist **stack);
void		sa(t_clist **stack_a);
void		sb(t_clist **stack_b);
void		ss(t_clist **stack_a, t_clist **stack_b);

void		rotation(t_clist **stack);
void		ra(t_clist **stack_a);
void		rb(t_clist **stack_b);
void		rr(t_clist **stack_a, t_clist **stack_b);

void		reverse_rotation(t_clist **stack);
void		rra(t_clist **stack_a);
void		rrb(t_clist **stack_b);
void		rrr(t_clist **stack_a, t_clist **stack_b);

// Radix Sort
int			stack_is_sorted(t_clist *stack);
void		radix_sort(t_clist **stack_a, t_clist **stack_b, int size);

// Small Sort
void		sort_stack_3(t_clist **stack);
int			get_nbr_position(t_clist *stack, int nbr);
void		get_to_top(t_clist **stack_a, int size, int nbr);
void		select_sort(t_clist **stk_a, t_clist **stk_b, int size, int min);

#endif
