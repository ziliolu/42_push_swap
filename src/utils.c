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

int add_node_front(t_stack *stack, t_node *newNode)
{
    t_node *last;
    //t_node *tmp;
    stack->size += 1; 
    if(!stack->top)
    {
		newNode->next = newNode;
    	newNode->prev = newNode;
        stack->top = newNode;
        return (1);
    }
    last = find_last_node(*stack);
	stack->top->prev = newNode;
	newNode->next = stack->top;
	newNode->prev = last;
	last->next = newNode;
	stack->top = newNode;

    return (1);
}

// int pop(t_stack *stack)
// {
// 	int tmp;
// 	t_node *pop_node;

// 	pop_node = NULL;

// 	if (stack->size < 1 || !stack)
// 		return (0);
// 	else
// 	{
// 		tmp = stack->top->data;
// 		if(stack->top->data == stack->top->next->data)
// 			stack->top = NULL;
// 		else
// 		{	
// 			pop_node = stack->top;
// 			stack->top->prev->next = stack->top->next;
// 			stack->top->next->prev = stack->top->prev;
// 			stack->top = stack->top->next;
// 		}
// 	}
// 	//free(pop_node);
// 	stack->size--;
// 	return(tmp);
// }

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

// t_node *pop(t_stack *stack)
// {
// 	t_node *tmp;

// 	if (stack->size < 1 || !stack)
// 		return (NULL);
// 	else if(!stack->top)
// 		return (NULL);
// 	tmp = stack->top;	

// 	stack->top->prev->next = stack->top->next;
// 	stack->top->next->prev = stack->top->prev;
// 	stack->top = stack->top->next;

// 	stack->size--;

// 	tmp->next = NULL;
// 	tmp->prev = NULL;
// 	return(tmp);
// }