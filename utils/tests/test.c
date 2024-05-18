#include "stdio.h"

typedef struct s_list
{
	int data;
	struct s_list *next;
} t_list;

void	test_function(t_list **list)
{
	// printf("data 1: %d\n", (*list)->data);
	// printf("data 1: %d\n", (*(*list)).data);
	// printf("next 1: %p\n", (*list)->next);
	// printf("next 1: %p\n", (*(*list)).next);

	// printf("data addr: %p\n", &((*list)->data));
	// printf("next addr: %p\n", &((*list)->next));
	// printf("list : %p\n", *list);

}

int main(void)
{
	t_list node1;
	t_list node2;
	t_list *ptr;

	node1.data = 1;
	node1.next = &node2;

	node2.data = 2;
	node2.next = NULL;
	
	//printf("node1 addr : %p\n", &node1);
	//printf("node1 data addr : %p\n", &node1.data);
	//printf("node1 next addr : %p\n", &node1.next);
	
	ptr = &node1;
	printf("-> Pointer\n");
	printf("&ptr : %p\n", &ptr);
	printf(" ptr : %p\n", ptr);
	printf("*ptr : %p (NOT a pointer)\n", *ptr); // NOT a pointer
	printf("\n");
	
	printf("-> Node1 address\n");
	printf("&node1 : %p\n", &node1);
	printf(" node1 : %p (NOT a pointer)\n", node1); // NOT a pointer
	printf("\n");

	printf("-> Node2 address\n");
	printf("&node2 : %p\n", &node2);
	printf(" node2 : %p (NOT a pointer)\n", node2); // NOT a pointer
	printf("\n");

	printf("-> Node1 data\n");
	printf("      node1.data : %d\n", node1.data);
	printf("  (&node1)->data : %d\n", (&node1)->data);
	printf("(*(&node1)).data : %d\n", (*(&node1)).data);
	printf("\n");

	printf("-> Node1 next\n");
	printf("      node1.next : %p\n", node1.next);
	printf("  (&node1)->next : %p\n", (&node1)->next);
	printf("(*(&node1)).next : %p\n", (*(&node1)).next);
	printf("\n");

	printf("-> Node2 data\n");
	printf("      node2.data : %d\n", node2.data);
	printf("  (&node2)->data : %d\n", (&node2)->data);
	printf("(*(&node2)).data : %d\n", (*(&node2)).data);
	printf("\n");

	printf("-> Node2 next\n");
	printf("      node2.next : %p\n", node2.next);
	printf("  (&node2)->next : %p\n", (&node2)->next);
	printf("(*(&node2)).next : %p\n", (*(&node2)).next);
	printf("\n");

	printf("-> Pointer to node1 - data\n");
	printf("       ptr->data : %d\n", ptr->data);
	printf("     (*ptr).data : %d\n", (*ptr).data);

	//printf("  (&node1)->next : %p\n", (&node1)->next);
	//printf("(*(&node1)).next : %p\n", (*(&node1)).next);
	printf("\n");


	test_function(&ptr);
	return 0;
}