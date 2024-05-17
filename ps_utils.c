/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toantune <toantune@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 13:59:33 by toantune          #+#    #+#             */
/*   Updated: 2024/04/29 20:54:51 by toantune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#define DEBUG
#include "push_swap.h"

long int	*convert_argv(int size, char **argv)
{
	long int	*arr;
	int			i;
	int			j;

	LOG_MESSAGE("start function\n");
	if (!size || !argv)
		error();
	LOG_MESSAGE("populate array\n");
	arr = malloc(sizeof(long int) * (size));
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
	//print_arr("arr ", arr, argc - 1);
	return (arr);
}

void	swap(t_clist **stack)
{
	t_clist	*first;
	t_clist	*second;

	if (*stack && (*stack)->next != *stack)
	{
		first = *stack;
		second = first->next;
		first->next = second->next;
		second->next->prev = first;
		second->next = first;
		second->prev = first->prev;
		first->prev->next = second;
		first->prev = second;
		*stack = second;
	}
}

int	*map_index(long int *arr, int size)
{
	int		*index;
	int		i;
	int		j;

	index = malloc(sizeof(int) * size);
	if (!index)
		return (0);
	i = 0;
	while (i < size)
	{
		index[i] = 0;
		j = 0;
		while (j < size)
		{
			if ((int)arr[j] < (int)arr[i])
				index[i]++;
			j++;
		}
		i++;
	}
	return (index);
}

void	print_argv(char *message, char **argv)
{
	int	i;

	(void)message;
	LOG_MESSAGE("%s", message);
	i = 0;
	while (argv[i] != NULL)
	{
		ft_putstr_fd(argv[i], 1);
		ft_putstr_fd(" ", 1);
		i++;
	}
	ft_putstr_fd("\n", 1);
}

void	print_arr(char *message, long int *arr, int size)
{
	int	i;

	(void)message;
	LOG_MESSAGE("%s", message);
	i = 0;
	while (i < size)
	{
		printf("%ld ", arr[i]);
		i++;
	}
	printf("\n");
}

void	print_stack(char *message, t_clist *stack)
{
	t_clist	*current;

	(void)message;
	if (stack == NULL)
		return ;
	//LOG_MESSAGE(message);
	current = stack;
	ft_printf("\t");
	while (1)
	{
		ft_printf("%d\t", current->index);
		current = current->next;
		if (current == stack)
			break ;
	}
	printf("\n");
	current = stack;
	ft_printf("\t");
	while (1)
	{
		ft_printf("%d\t", current->data);
		current = current->next;
		if (current == stack)
			break ;
	}
	ft_putstr_fd("\n", 1);
}

