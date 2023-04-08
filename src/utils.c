#include "../includes/push_swap.h"

void run_utils(t_utils *u, t_stack *a, t_stack *b)
{
	while(u->a_rotate != 0 || u->b_rotate != 0 || u->a_reverse_rotate != 0 || u->b_reverse_rotate != 0 || u->rr != 0 || u->rrr != 0)
		{
			if(u->a_rotate > 0)
			{
				rotate(a, 1);
				u->a_rotate--;
			}
			if(u->b_rotate > 0)
			{
				rotate(b, 1);
				u->b_rotate--;
			}
			if(u->a_reverse_rotate > 0)
			{
				reverse_rotate(a, 1);
				u->a_reverse_rotate--;
			}
			if(u->b_reverse_rotate > 0)
			{
				reverse_rotate(b, 1);
				u->b_reverse_rotate--;
			}
			if(u->rr > 0)
			{
				rr(a, b);
				u->rr--;
			}
			if(u->rrr > 0)
			{
				rrr(a, b);
				u->rrr--;
			}
		}
}

// void run_utils(t_utils *u, t_stack *a, t_stack *b)
// {
// 	while(u->a_rotate != 0 || u->b_rotate != 0 || u->a_reverse_rotate != 0 || u->b_reverse_rotate != 0 || u->rr != 0 || u->rrr != 0)
// 	{
// 		if(u->a_rotate > 0)
// 		{
// 			rotate(a, 1);
// 			u->a_rotate--;
// 		}
// 		if(u->b_rotate > 0)
// 		{
// 			rotate(b, 1);
// 			u->b_rotate--;
// 		}
// 		if(u->rr > 0)
// 		{
// 			rr(a, b);
// 			u->rr--;
// 		}
// 		run_reverse_rotate(u, a, b);
// 	}
// }

// void run_reverse_rotate(t_utils *u, t_stack *a, t_stack *b)
// {
// 	if(u->a_reverse_rotate > 0)
// 	{
// 		reverse_rotate(a, 1);
// 		u->a_reverse_rotate--;
// 	}
// 	if(u->b_reverse_rotate > 0)
// 	{
// 		reverse_rotate(b, 1);
// 		u->b_reverse_rotate--;
// 	}
// 	if(u->rrr > 0)
// 	{
// 		rrr(a, b);
// 		u->rrr--;
// 	}
// }

t_node *newNode(int data)
{
	t_node *node;

	node = malloc(sizeof(t_node));
	if(node)
	{
		node->data = data;
		node->next = NULL;
		node->prev = NULL;
	}
    return (node);
}

t_node *find_last_node(t_stack stack)
{
	int i;
	t_node *node;

	i = 0;
	node = stack.top;
	while(i < stack.size && node->next != stack.top)
	{
		node = node->next;
		i++;
	}
	return(node);
}

int pop(t_stack *stack)
{
	int tmp;

	if (stack->size < 1 || !stack)
		return (0);
	else
	{
		tmp = stack->top->data;
		if(stack->top->data == stack->top->next->data)
			stack->top = NULL;
		else
		{
			stack->top->prev->next = stack->top->next;
			stack->top->next->prev = stack->top->prev;
			stack->top = stack->top->next;
		}
	}
	stack->size--;
	return(tmp);
}
