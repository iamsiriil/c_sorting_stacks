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

int	log_count = 0;

static char	*create_arg_str(int argc, char **argv, size_t size)
{
	char	*arg_str;
	int		i;

	arg_str = malloc(sizeof(char) * (size + argc));
	if (!arg_str)
		return (NULL);
	arg_str[0] = '\0';

	i = 1;
	while (i < argc)
	{
		ft_strlcat(arg_str, argv[i], size + argc);
		if (i != argc - 1)
			ft_strlcat(arg_str, " ", size + argc);
		i++;
	}
	return (arg_str);
}

static char	**arg_parser(int argc, char **argv) 
{
	size_t	total_size;
	char	*arg_str;
	char	**vec_ptr;
	int		i;

	i = 1;
	total_size = 0;
	while (i < argc)
	{
		total_size += ft_strlen(argv[i]) + 1;
		i++;
	}
	arg_str = create_arg_str(argc, argv, total_size);
	vec_ptr = ft_split(arg_str, ' ');
	free(arg_str);
	return (vec_ptr);
}

int	get_size(char **args)
{
	int	i;

	i = 0;
	while (args[i] != NULL)
		i++;
	return (i);
}

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
	print_argv("arg_vec : ", arg_vec);

	int	size = get_size(arg_vec);
	LOG_MESSAGE("number of elements in arg_vec: %d\n", size);


	checker(size, arg_vec, &stack_a);
	LOG_MESSAGE("checker completed\n");

	//if (size >= 5)
		//small_sort
	//else
		//radix_sort(&stack_a, &stack_b, size);

	print_stack("\n", stack_a);
	LOG_MESSAGE("free stacks and terminate program\n");
	free_clist(stack_a);
	free_clist(stack_b);
	return (0);
}
