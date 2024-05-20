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

char	*create_arg_str(int argc, char **argv, size_t size)
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

char	**arg_parser(int argc, char **argv) 
{
	size_t	tsize;
	char	*arg_str;
	char	**vec_ptr;
	int		i;

	i = 1;
	tsize = 0;
	while (i < argc)
	{
		tsize += ft_strlen(argv[i]) + 1;
		i++;
	}
	arg_str = create_arg_str(argc, argv, tsize);
	vec_ptr = ft_split(arg_str, ' ');
	free(arg_str);
	return (vec_ptr);
}