/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toantune <toantune@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 14:30:58 by toantune          #+#    #+#             */
/*   Updated: 2024/04/29 20:51:49 by toantune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define DEBUG
#include "./push_swap.h"
#include "./test_push_swap.h"

int	log_count = 0;

int	main(int argc, char **argv)
{
	t_clist		*stack_a;
	t_clist		*stack_b;
	char		**arg_vec;

	LOG_MESSAGE("start\n");
	if (argc <= 1)
		return (0);
	else
		arg_vec = arg_parser(argc, argv);

	LOG_MESSAGE("number of arguments: %d\n", argc);
	stack_a = NULL;
	stack_b = NULL;
	LOG_MESSAGE("initialize stacks: stack_a in: %p; stack_b in: %p\n", (void*)&stack_a, (void*)&stack_b);
	LOG_MESSAGE("arg_vec: ");
	print_argv(arg_vec);

	int	size = get_argv_size(arg_vec);
	LOG_MESSAGE("number of elements in arg_vec: %d\n", size);


	checker(size, arg_vec, &stack_a);
	LOG_MESSAGE("checker completed\n");

	//if (size >= 5)
		//small_sort
	//else
		//radix_sort(&stack_a, &stack_b, size);

	LOG_MESSAGE("stack_a :\n");
	print_stack(stack_a);
	LOG_MESSAGE("free stacks and terminate program\n");
	free_clist(stack_a);
	free_clist(stack_b);
	return (0);
}
