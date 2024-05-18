/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toantune <toantune@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 14:30:58 by toantune          #+#    #+#             */
/*   Updated: 2024/04/18 10:08:55 by toantune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "./push_swap.h"

int main()
{
    t_clist *stack_a = NULL, *stack_b = NULL;

    // Populate stack_a for demonstration
    int nums[] = {53, 89, 150, 36, 633, 233, 2, 159, 455, 162}, n = 10;
    for (int i = 0; i < n; i++)
        push_clist(&stack_a, create_clist_node(nums[i]));

    radix_sort(&stack_a, &stack_b);

    print_stacks(stack_a, stack_b);  // Function to print the stack
    free_clist(stack_a);
    free_clist(stack_b);
    return 0;
}
