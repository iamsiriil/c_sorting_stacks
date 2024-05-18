/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toantune <toantune@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 13:39:31 by parrot            #+#    #+#             */
/*   Updated: 2024/04/23 18:07:03 by toantune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

long int	ft_atol(const char *str);

static int	ft_isspace(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

long int	ft_atol(const char *str)
{
	long long	nbr;
	int			sign;

	while (ft_isspace(*str))
		str++;
	sign = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	nbr = 0;
	while (ft_isdigit(*str))
	{
		nbr = nbr * 10 + (*str - 48);
		if ((sign == 1 && nbr > LONG_MAX) || (sign == -1 && - nbr < LONG_MIN))
		{
			ft_putendl_fd("Error: Number out of range", 2);
			exit(1);
		}
		str++;
	}
	return (nbr * sign);
}
