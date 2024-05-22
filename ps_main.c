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

#include "./push_swap.h"

int	main(int argc, char **argv)
{
	t_clist		*stack_a;
	t_clist		*stack_b;
	char		**arg_vec;
	int			size;

	if (argc == 1)
		return (0);
	else
		arg_vec = arg_parser(argc, argv);
	stack_a = NULL;
	stack_b = NULL;
	size = get_argv_size(arg_vec);
	checker(arg_vec, size, &stack_a);
	if (size <= 10)
		select_sort(&stack_a, &stack_b, size, 0);
	else
		radix_sort(&stack_a, &stack_b, size);
	free_clist(stack_a);
	free_clist(stack_b);
	return (0);
}
