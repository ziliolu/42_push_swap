#include "../includes/push_swap.h"

int rotate(t_stack *stack, bool op)
{
    if (stack->size >= 2)
    {
        stack->top = stack->top->next;
        if(op)
            printf("r%c\n", stack->charac);
        return (1);
    }
    return (-1);
}

int rr(t_stack *a, t_stack *b)
{
	if(a->size >= 2 && b->size >= 2)
	{
		printf("rr\n");
		rotate(a, 0);
		rotate(b, 0);
		return (1);
	}
	return (-1);
}