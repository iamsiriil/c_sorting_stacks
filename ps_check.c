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

#include "push_swap.h"

void	check_char(char **arg_vec, int size)
{
	int	i;
	int	j;

	if (!arg_vec)
		error((void **)arg_vec, size);
	i = 0;
	while (arg_vec[i])
	{
		j = 0;
		if (arg_vec[i][j] == '+' || arg_vec[i][j] == '-')
			j++;
		if (!ft_isdigit(arg_vec[i][j]))
			error((void **)arg_vec, size);
		while (arg_vec[i][j])
		{
			if (!ft_isdigit(arg_vec[i][j]))
				error((void **)arg_vec, size);
			j++;
		}
		i++;
	}
}

void	check_dup(long int *arr_vec, int size)
{
	int	i;
	int	j;

	if (!arr_vec)
		error((void **)&arr_vec, 1);
	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr_vec[i] == arr_vec[j])
				error((void **)&arr_vec, 1);
			j++;
		}
		i++;
	}
}

void	check_int(long int *arr_vec, int size)
{
	int	i;

	if (!arr_vec)
		error((void **)&arr_vec, 1);
	i = 0;
	while (i < size)
	{
		if (arr_vec[i] >= INT_MAX || arr_vec[i] <= INT_MIN)
			error((void **)&arr_vec, 1);
		i++;
	}
}

void	check_sort(long int *arr_vec, int size)
{
	int	i;

	if (!arr_vec)
		error((void **)&arr_vec, 1);
	i = 1;
	while (i < size)
	{
		if (arr_vec[i] < arr_vec[i - 1])
			return ;
		i++;
	}
	free(arr_vec);
	exit(EXIT_FAILURE);
}

void	checker(char **arg_vec, int size, t_clist **stack_a)
{
	long int	*arr;
	int			*idx;
	int			i;

	check_char(arg_vec, size);
	arr = convert_argv(size, arg_vec);
	free(arg_vec);
	check_dup(arr, size);
	check_int(arr, size);
	check_sort(arr, size);
	idx = map_index(arr, size);
	i = size - 1;
	while (i >= 0)
	{
		push_clist(stack_a, create_clist_node((int)arr[i], idx[i]));
		i--;
	}
	free(idx);
	free(arr);
}
