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

#ifndef TEST_PUSH_SWAP_H
# define TEST_PUSH_SWAP_H

# include <stdio.h>
# include "./push_swap.h"

extern int log_count;

# ifdef DEBUG
# define LOG_MESSAGE(format, ...) \
    do { \
		printf("%03d: in %s: in %s: ", ++log_count, __FILE__, __func__); \
        printf(format, ##__VA_ARGS__); \
		fflush(stdout); \
    } while (0)
# else
# define LOG_MESSAGE(format, ...)
# endif

// Test utils
void		print_argv(char **argv);
void		print_arr(long int *arr, int size);
void		print_stack(t_clist *stack);

#endif