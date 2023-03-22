#include "../includes/push_swap.h"

int verify_two_elements(t_stack stack)
{
	if ((!stack.top || !stack.top->next) || stack.top == stack.top->next ) // verificar se há no minimo dois elementos
    {
        printf("-> não há elementos suficientes p/ operacao\n");
        return (-1);
    }
	return (1);
}
