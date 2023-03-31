#include "../includes/push_swap.h"


int find_highest_number(t_stack *b)
{
	int i;
	int max;

	i = 0;
	max = 0;
	while(i < b->size)
	{
		if(b->top->data > max)
			max = b->top->data;
		b->top = b->top->next;
		i++;
	}
	return(max);
}

int find_lowest_number(t_stack *b)
{
	int i;
	int min;

	i = 0;
	min = b->top->data;
	while(i < b->size)
	{
		if(b->top->data < min)
			min = b->top->data;
		b->top = b->top->next;
		i++;
	}
	return(min);
}

int find_match_number(int a_data, t_stack *b)
{
	int i;
	int match;

	(void)a_data;
	i = 0;
	match = find_lowest_number(b);
	if (a_data > find_highest_number(b) || a_data < find_lowest_number(b))
		return (find_highest_number(b));
	else
	{
		while(i < b->size)
		{
			if(b->top->data < a_data && b->top->data > match)
				match = b->top->data;
			b->top = b->top->next;
			i++;
		}
	}
	return(match);
}

int push_swap_init(t_stack *a, t_stack *b)
{
	t_utils utils;
	int match;

	init_utils(&utils);
	// t_utils utils;
	// init_utils(&utils);
	//count_moves(*a, *b, utils);

	// printf("match number %d\n", find_match_number(6, b));
	// printf("highest number: %d\n", find_highest_number(b));
	// printf("lowest number: %d\n", find_lowest_number(b));
	// printf("index: %d\n", find_index(a->top->next->next->data, *a));

	(void)a;
	print_utils(&utils); 
	int n = 39;
	count_moves(n, a, &utils);
	match = find_match_number(n, b);
	count_moves(match, b, &utils);
	print_utils(&utils); 
	printf("total de movimentos: %d\n", sum_moves(&utils));
	return(1);
}

int sum_moves(t_utils *utils)
{
	int sum;

	sum = 0;
	if (utils->b_rotate > utils->a_rotate)
		sum += utils->b_rotate;
	else 
		sum += utils->a_rotate;
	
	if (utils->b_reverse_rotate > utils->a_reverse_rotate)
		sum += utils->b_reverse_rotate;
	else 
		sum += utils->a_reverse_rotate;
	return(sum);
}

void count_moves(int data, t_stack *stack, t_utils *utils)
{

	int index_node;
	int middle_index;

	index_node = find_index(data, *stack);
	middle_index = stack->size / 2;

	if(index_node == 0)
	{
		printf("index 0 - nao faz nada\n");
	}
	else if(index_node == middle_index || index_node <= middle_index)
	{
		if(stack->charac == 'a')
			utils->a_rotate = index_node;
		else if(stack->charac == 'b')
			utils->b_rotate = index_node;
	}
	else
	{
		if(stack->charac == 'a')
			utils->a_reverse_rotate = stack->size - index_node;
		else if(stack->charac == 'b')
			utils->b_reverse_rotate = stack->size - index_node;
	}
}