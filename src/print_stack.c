#include "../includes/push_swap.h"

int	print_stack(t_stack *a, t_stack *b)
{
	int	i;

	i = 0;
	ft_printf("== a ==\n");
	if(a->top != NULL )
	{   
		while(i++ < a->size)
		{
			printf("  %d   \n", a->top->data);
			a->top = a->top->next;
		}
	}
	ft_printf("== b ==\n");
	if(b->top != NULL)
	{
		i = 0;
		while(i++ < b->size)
		{
			printf("  %d   \n", b->top->data);
			b->top = b->top->next;
		}
	}
	ft_printf("=======\n\n");
	return (1);
}

void print_info(t_stack stack)
{
	printf("==== info stack %c ====\n", stack.charac);
	printf("->top node: %d\n", stack.top->data);
	printf("next do top node: %d\n", stack.top->next->data);
	printf("next do next do top node (segundo): %d\n", stack.top->next->next->data);
	printf("prev do top node: %d\n", stack.top->prev->data);
	printf("last node: %d\n", find_last_node(stack)->data);
	printf("prev do last node: %d\n", find_last_node(stack)->prev->data);
	printf("next do last node: %d\n", find_last_node(stack)->next->data);
	printf("->size da stack: %d\n\n", stack.size);
}

void print_utils(t_utils *utils)
{
	printf("\n===== utils =====\n");
	printf("a_data: %d\n", utils->a_data);
	printf("b_data: %d\n", utils->b_data);
	printf("a_rotate: %d\n", utils->a_rotate);
	printf("b_rotate: %d\n", utils->b_rotate);
	printf("a_reverse_rotate: %d\n", utils->a_reverse_rotate);
	printf("b_reverse_rotate: %d\n", utils->b_reverse_rotate);
	printf("rr: %d\n", utils->rr);
	printf("rrr: %d\n\n", utils->rrr);
}
