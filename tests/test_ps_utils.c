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

void	print_argv(char **argv)
{
	int	i;

    i = 0;
	while (argv[i] != NULL)
	{
		ft_putstr_fd(argv[i], 1);
		ft_putstr_fd(" ", 1);
		i++;
	}
	ft_putstr_fd("\n", 1);
}

void	print_arr(long int *arr, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		printf("%ld ", arr[i]);
		i++;
	}
	printf("\n");
}

void	print_stack(t_clist *stack)
{
	t_clist	*current;

	if (stack == NULL)
		return ;

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
