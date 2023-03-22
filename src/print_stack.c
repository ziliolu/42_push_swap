#include "../includes/push_swap.h"

int print_stack(t_stack a, t_stack b) //nao utilizar * para poder criar apenas copia
{
    int i;

    i = 0;
    printf("== a ==\n");
    if(a.top != NULL )
    {   
        while(i++ < a.size)
        {
            printf("  %d   \n", a.top->data);
            a.top = a.top->next;
        }
    }
    printf("== b ==\n");
    if(b.top != NULL)
    {
        i = 0;
        while(i++ < b.size)
        {
            printf("  %d   \n", b.top->data);
            b.top = b.top->next;
        }
    }
    printf("=======\n\n");
    return (1);
}

void print_info(t_stack stack)
{
    printf("--- INFO STACK %c ---\n", stack.charac);
    printf("top node: %d\n", stack.top->data);
	printf("next do top node: %d\n", stack.top->next->data);
    printf("next do next do top node (segundo): %d\n", stack.top->next->next->data);
	printf("prev do top node: %d\n", stack.top->prev->data);
	printf("last node: %d\n", find_last_node(stack)->data);
	printf("prev do last node: %d\n", find_last_node(stack)->prev->data);
	printf("next do last node: %d\n", find_last_node(stack)->next->data);
	printf("size da stack: %d\n\n", stack.size);
}