#include "../includes/push_swap.h"

int reverse_rotate(t_stack *stack, bool op)
{
// <<<<<<< HEAD
    if (stack->size >= 2)
    {
		stack->top = stack->top->prev;
		if(op)
			printf("rr%c\n", stack->charac);
		return (1);
    }
	return (-1);
// =======
//     if(verify_two_elements(*stack) == 1)
//     {
//         printf("rr%c\n", stack->charac);
//         stack->top = find_last_node(*stack);
//         return (1);
//     }
//     return (-1);
// >>>>>>> bff7121e5519ddaa03ff20f0cca9a35b66da8b6a
}

int rrr(t_stack *a, t_stack *b)
{
// <<<<<<< HEAD
	if(a->size >= 2 && b->size >= 2)
	{
		printf("rrr\n");
		reverse_rotate(a, 0);
		reverse_rotate(b, 0);
		return (1);
	}
	return (-1);
// =======
//     if(verify_two_elements(*a) == 1 && verify_two_elements(*b))
//     {
//         reverse_rotate(a);
//         reverse_rotate(b);
//         return (1);
//     }
//     return (-1);
// >>>>>>> bff7121e5519ddaa03ff20f0cca9a35b66da8b6a
}