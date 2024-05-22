/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toantune <toantune@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 15:18:24 by toantune          #+#    #+#             */
/*   Updated: 2024/04/24 08:16:25 by toantune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(void **ptr, int size)
{
	int	i;

	if (ptr != NULL && size != 0)
	{
		i = 0;
		while (i < size)
		{
			free(ptr[i]);
			i++;
		}
	}
	ft_putendl_fd("Error", 2);
	exit(EXIT_FAILURE);
}
