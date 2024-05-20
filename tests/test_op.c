#include <stdlib.h>
#include "../ps_error.c"
#include "../ps_check.c"
#include "../ps_clist.c"
#include "../ps_utils.c"
#include "../ps_opr_push.c"
#include "../ps_opr_swap.c"
#include "../ps_opr_rotation.c"
#include "../ps_opr_rev_rotation.c"
#include "../libft/libft.h"
#include "../push_swap.h"
#include "../test_ps_utils.c"
#include "../test_push_swap.h"

void	print_stacks(t_clist *stack_a, t_clist *stack_b)
{
	int size_a = count_nodes(stack_a);
	int size_b = count_nodes(stack_b);
	int size_max = 0;

	if (size_a >= size_b)
		size_max = size_a;
	else
		size_max = size_b;

	int i = size_max;
	while (i >= 1)
	{
		if (i <= size_a)
		{
			printf("\t%d", stack_a->data);
			stack_a = stack_a->next;
		}
		else
			printf("\t");
		if (i <= size_b)
		{
			printf("\t%d", stack_b->data);
			stack_b = stack_b->next;
		}
		else
			printf("\t");
		printf("\n");
		i--;
	}
	printf("\t___\t___\n");
	printf("\t a\t b\n");
}

int	main(void)
{
	t_clist	*stack_a = NULL;
	t_clist *stack_b = NULL;
	int	arr[10] = {1, 9, -54, -97, 124, 5678, 78, -85, -2, 354};

	int i = 9;
	while (i >= 0)
	{
		push_clist(&stack_a, create_clist_node(arr[i], 0));
		i--;
	}

	char opr[10];

	while (1)
	{
		scanf("%s", opr);
		system("clear");

		if (ft_strcmp(opr, "exit") == 0)
			break;

		if (ft_strcmp(opr, "pa") == 0)
			pa(&stack_a, &stack_b);
		else if (ft_strcmp(opr, "pb") == 0)
			pb(&stack_a, &stack_b);
		else if (ft_strcmp(opr, "sa") == 0)
			sa(&stack_a);
		else if (ft_strcmp(opr, "sb") == 0)
			sa(&stack_b);
		else if (ft_strcmp(opr, "ss") == 0)
			ss(&stack_a, &stack_b);
		else if (ft_strcmp(opr, "ra") == 0)
			ra(&stack_a);
		else if (ft_strcmp(opr, "rb") == 0)
			rb(&stack_b);
		else if (ft_strcmp(opr, "rr") == 0)
			rr(&stack_a, &stack_b);
		else if (ft_strcmp(opr, "rra") == 0)
			rra(&stack_a);
		else if (ft_strcmp(opr, "rrb") == 0)
			rrb(&stack_b);
		else if (ft_strcmp(opr, "rrr") == 0)
			rrr(&stack_a, &stack_b);
		else
		{
			printf("Invalid command!\n");
			continue ;
		}
		print_stacks(stack_a, stack_b);
	}
	return (0);
}


