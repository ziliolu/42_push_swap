#include "../includes/push_swap.h"

void count_moves(t_stack a, t_stack b)
{
	int i;
	int index_node;
	int middle_index;
	t_node *tmp;
	(void)b;

	i = 0;
	tmp = a.top;
	while(i < a.size)
	{
		index_node = find_index(a, tmp);
		printf("elemento: %d | index: %d\n", tmp->data, index_node);
		middle_index = a.size / 2;
		if(index_node == 0)
		{
			tmp->rotate = 0;
			tmp->reverse_rotate = 0;
		}
		else if(index_node == middle_index)
		{
			tmp->rotate = middle_index;
			tmp->reverse_rotate = 0;
			printf("index igual, vai ser feito rotate %d vezes\n", tmp->rotate);
			printf("index do elemento: %d\n", index_node);
			printf("index medio: %d\n\n", middle_index);
		}
		else if((index_node <= middle_index))
		{
			tmp->rotate = middle_index - index_node;
			tmp->reverse_rotate = 0;
			printf("index menor, vai ser feito rotate %d vezes\n", tmp->rotate);
			printf("index do elemento: %d\n", index_node);
			printf("index medio: %d\n\n", middle_index);
		}
		else
		{
			tmp->rotate = 0;
			tmp->reverse_rotate = a.size - index_node;
			printf("index menor, vai ser feito reverse rotate %d vezes\n", tmp->reverse_rotate);
			printf("index do elemento: %d\n", index_node);
			printf("index medio: %d\n\n", middle_index);
		}
		i++;
		tmp = tmp->next;
	}

	//retornara o index do elemento da stack a com o menor numero de movimentos. 
}

int push_swap_init(t_stack *a, t_stack *b)
{
	// int index_node;
	// int middle_index;
	// t_node *tmp;

	(void)b;
	//index_node = find_index(*a, a->top);
	count_moves(*a, *b);
	return(1);
}