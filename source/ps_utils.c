/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toantune <toantune@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 13:59:33 by toantune          #+#    #+#             */
/*   Updated: 2024/04/23 16:17:41 by toantune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(void)
{
	ft_putendl_fd("Error", 2);
	exit(1);
}

long int	*convert_argv(int argc, char **argv)
{
	long int	*arr;
	int			i;
	int			j;

	if (!argc || !argv)
		error();
	arr = malloc(sizeof(long int) * (argc - 1));
	if (!arr)
		error();
	i = 1;
	j = 0;
	while (argv[i])
	{
		arr[j] = ft_atol(argv[i]);
		i++;
		j++;
	}
	return (arr);
}

void	check_char(char **argv)
{
	int	i;
	int	j;

	if (!argv)
		error();
	i = 0;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]) && !(argv[i][j] == '-' && j == 0))
				error();
			j++;
		}
		i++;
	}
}

void	check_duplicates(long int *arr, int size)
{
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
	int	i;

	if (!arr)
		error();
	i = 0;
	while (i < size)
	{
		if (arr[i] >= MAX_INT || arr[i] <= MIN_INT)
		{
			free(arr);
			error();
		}
		i++;
	}
}

int	check_sort(long int *arr, int size)
{
	int	i;

	if (!arr)
		error();

	i = 1;
	while (i < size)
	{
		if (arr[i] < arr[i - 1])
			return (0);
		i++;
	}
	free(arr);
	return (1);
}

void	checker(int argc, char **argv, t_clist **stack_a)
{
	long int	*arr;
	int			i;

	check_char(argv);
	arr = convert_argv(argc, argv);
	check_duplicates(arr, argc - 1);
	check_int(arr, argc - 1);

	i = 0;
	while (i < argc - 1)
	{
		push_clist(*stack_a, create_clist_node((int)arr[i]));
		i++;
	}
	free(arr);
}

int	main(int argc, char **argv)
{
	t_clist		*stack_a;
	t_clist		*stack_b;
	long int	*arr;

	if (argc <= 1)
		return (0);

	arr = convert_argv(argc, argv);
	if (check_sort(arr, argc - 1))
		return (0);

	stack_a = NULL;
	stack_b = NULL;
	checker(argc, argv, &stack_a);
	radix_sort(&stack_a, &stack_b);
	free_clist(stack_a);
	free_clist(stack_b);

	return (0);
}
