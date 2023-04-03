#include "../includes/push_swap.h"

t_node *newNode(int data)
{
    t_node *node;
    
    node = malloc(sizeof(node));
    node->data = data;
    node->next = NULL;
    node->prev = NULL;
    
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