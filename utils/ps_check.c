/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toantune <toantune@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 20:55:09 by toantune          #+#    #+#             */
/*   Updated: 2024/04/29 10:44:29 by toantune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define DEBUG
#include "push_swap.h"

void	check_char(char **argv)
{
	LOG_MESSAGE("function call\n");
	int	i;
	int	j;
	

	if (!argv)
		error();
	
	//print_argv("argv ", argv);
	i = 1;
	while (argv[i])
	{
		j = 0;
		if (argv[i][j] == '+' || argv[i][j] == '-')
			j++;
		if (!ft_isdigit(argv[i][j]))
			error();
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
				error();
			j++;
		}
		i++;
	}
}

void	check_dup(long int *arr, int size)
{
	LOG_MESSAGE("function call\n");
	int	i;
	int	j;

	if (!arr)
		error();


	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] == arr[j])
			{
				free(arr);
				error();
			}
			j++;
		}
		i++;
	}
}

void	check_int(long int *arr, int size)
{
	LOG_MESSAGE("function call\n");
	int	i;

	if (!arr)
		error();
	i = 0;

	while (i < size)
	{
		if (arr[i] >= INT_MAX || arr[i] <= INT_MIN)
		{
			free(arr);
			error();
		}
		i++;
	}
}

void	check_sort(long int *arr, int size)
{
	LOG_MESSAGE("function call\n");
	int	i;

	if (!arr)
		error();


	i = 1;
	while (i < size)
	{
		if (arr[i] < arr[i - 1])
		{
			LOG_MESSAGE("array NOT sorted. end function\n");
			return ;
		}
		i++;
	}
	LOG_MESSAGE("array is sorted. close program\n");
	free(arr);
	exit(1);
}

void	checker(int size, char **argv, t_clist **stack_a)
{
	LOG_MESSAGE("start checker\n");
	long int	*arr;
	int			*idx;
	int			i;


	check_char(argv);
	arr = convert_argv(size, argv);
	check_dup(arr, size);
	check_int(arr, size);
	check_sort(arr, size);

	idx = map_index(arr, size);

	LOG_MESSAGE("populate stack\n");
	i = size - 1;
	while (i >= 0)
	{
		push_clist(stack_a, create_clist_node((int)arr[i], idx[i]));
		i--;
	}
	int size_stack = count_nodes(*stack_a);
	LOG_MESSAGE("size of stack_a: %d\n", size_stack);
	print_stack("\n", *stack_a);
	free(arr);
	LOG_MESSAGE("checker completed!\n");
}
