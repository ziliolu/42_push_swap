#include "../includes/push_swap.h"

int is_organized(t_stack stack)
{
	t_node *tmp;
	t_node *head;
	int i = 0;

	head = stack.top;
	while(i < stack.size && stack.top->next != head)
	{
		tmp = stack.top;
		if(stack.top->next->data < tmp->data)
			return (-1);
		stack.top = stack.top->next;
		i++;
	}
	return (1);
}