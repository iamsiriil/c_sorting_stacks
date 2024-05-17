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
# include <stdio.h>
# include "./libft/libft.h"

extern int log_count;

#ifdef DEBUG
#define LOG_MESSAGE(format, ...) \
    do { \
		printf("%03d: in %s: ", ++log_count, __func__); \
        printf(format, ##__VA_ARGS__); \
		fflush(stdout); \
    } while (0)
#else
#define LOG_MESSAGE(format, ...)
#endif


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
void		swap(t_clist **stack);
int			*map_index(long int *arr, int size);
void		print_argv(char *message, char **argv);
void		print_arr(char *message, long int *arr, int size);
void		print_stack(char *message, t_clist *stack);

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
//int			max_bit_position(t_clist *stack);
void		radix_sort(t_clist **stack_a, t_clist **stack_b, int argc);

#endif
