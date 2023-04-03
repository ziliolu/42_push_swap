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

// int push_swap_init(t_stack *a, t_stack *b)
// {
// 	t_utils utils;

// 	init_utils(&utils);
// 	(void)a;

// 	int i;
// 	static int sum;
// 	t_node *tmp;

// 	if(!a || !a->top)
// 		return (0);
// 	i = 0;
// 	sum = 0;
// 	tmp = a->top;
// 	count_moves(a->top->data, a, &utils);
// 	count_moves(find_match_number(a->top->data, b), b, &utils);
// 	sum = sum_moves(&utils);
// 	//a->top = a->top->next;

// 	if(!a->top)
// 		printf("ops!!1");
// 	while(i < a->size )
// 	{
		
// 		printf("top: %d\n", a->top->data);
// 		count_moves(a->top->data, a, &utils);
// 		print_utils(&utils);
// 		count_moves(find_match_number(a->top->data, b), b, &utils);
// 		print_utils(&utils);
// 		//sum = sum_moves(&utils);
// 		if(sum_moves(&utils) == 1 || sum_moves(&utils) == 0)
// 		{
// 			sum = sum_moves(&utils);
// 			break ; 
// 		}
// 		else if(sum_moves(&utils) < sum)
// 			sum = sum_moves(&utils);
// 		else
// 			init_utils(&utils);
// 		a->top = a->top->next;
// 		i++;
// 	}
// 	a->top = tmp;
// 	printf("movimentos: %d, numero mais barato de a: %d -> 
// 	equivalente em b: %d\n", sum, utils.a_data, utils.b_data);
// 	return(1);
// }

t_utils push_swap_init(t_stack *a, t_stack *b)
{
	t_utils utils;
	t_utils tmp_utils;

	init_utils(&utils);
	init_utils(&tmp_utils);
	(void)a;

	int i;
	static int sum;
	t_node *tmp;

	// if(!a || !a->top)
	// 	return (0);
	i = 0;
	sum = 0;
	tmp = a->top;
	count_moves(tmp->data, a, &utils);
	count_moves(find_match_number(tmp->data, b), b, &utils);
	tmp_utils = utils;
	sum = sum_moves(&utils);
	//a->top = a->top->next;

	if(!a->top)
		printf("ops!!1");
	while(i < a->size )
	{
		
		printf("top: %d\n", a->top->data);
		count_moves(tmp->data, a, &utils);
		count_moves(find_match_number(tmp->data, b), b, &utils);
		//sum = sum_moves(&utils);
		if(sum_moves(&utils) == 1 || sum_moves(&utils) == 0)
		{
			sum = sum_moves(&utils);
			break ; 
		}
		else if(sum_moves(&utils) < sum)
		{
			sum = sum_moves(&utils);
			tmp_utils = utils;
		}
		else
			init_utils(&utils);
		tmp = a->top->next;
		i++;
	}
	//a->top = tmp;
	printf("movimentos: %d, numero mais barato de a: %d -> \
	equivalente em b: %d\n", sum, tmp_utils.a_data, tmp_utils.b_data);
	return(tmp_utils);
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

	if(stack->charac == 'a')
		utils->a_data = data;
	if(stack->charac == 'b')
		utils->b_data = data;
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