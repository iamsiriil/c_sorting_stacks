#include <stdio.h>
#include <stdlib.h>

typedef struct s_clist
{
    int data;
    struct s_clist  *next;
    struct s_clist  *prev;
} t_clist;


int main(void)
{
    t_clist *node = malloc(sizeof(t_clist));
    t_clist node2;

    node->data = 45;
    node->next = &node2;
    node->next = &node2;

    printf("pointer: %p\n", node);
    printf("pointer - data: %p\n", &node->data);
    printf("pointer - next: %p\n", &node->next);
    printf("pointer - prev: %p\n", &node->prev);

    node2.data = 12;
    node2.next = node;
    node2.next = node;

    printf("pointer: %p\n", &node2);
    printf("pointer - data: %p\n", &node2.data);
    printf("pointer - next: %p\n", &node2.next);
    printf("pointer - prev: %p\n", &node2.prev);
    return (0);
}