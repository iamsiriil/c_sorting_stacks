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

typedef struct s_clist
{
	int				data;
	int				index;
	struct s_clist	*next;
	struct s_clist	*prev;
}	t_clist;

// Error
void		error(void);

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
void		check_char(char **argv);
void		check_dup(long int *arr, int size);
void		check_int(long int *arr, int size);
void		check_sort(long int *arr, int size);
void		checker(int size, char **argv, t_clist **stack_a);

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

void		ra(t_clist **stack_a);
void		rb(t_clist **stack_b);
void		rr(t_clist **stack_a, t_clist **stack_b);

void		rra(t_clist **stack_a);
void		rrb(t_clist **stack_b);
void		rrr(t_clist **stack_a, t_clist **stack_b);

// Radix
void		radix_sort(t_clist **stack_a, t_clist **stack_b, int argc);

#endif
