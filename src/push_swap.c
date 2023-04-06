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

int find_match_number(int data, t_stack *stack, bool perfect_match)
{
	int i;
	int match;

	i = 0;
	match = find_lowest_number(stack);
	if (data > find_highest_number(stack))
		return (find_highest_number(stack));
	else if(data < find_lowest_number(stack) && perfect_match == 0)
		return (find_highest_number(stack));
	else
	{
		while(i < stack->size)
		{
			if(stack->top->data < data && stack->top->data > match)
				match = stack->top->data;
			stack->top = stack->top->next;
			i++;
		}
	}
	return(match);
}


int find_perfect_match(int data, t_stack *stack)
{
	int i;
	int match;

	i = 0;
	match = find_highest_number(stack);
	if (data > find_highest_number(stack))
		return (find_lowest_number(stack));
	else
	{
		while(i < stack->size)
		{
			if(stack->top->data > data && stack->top->data < match)
				match = stack->top->data;
			stack->top = stack->top->next;
			i++;
		}
	}
	return(match);
}

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
	count_moves(find_match_number(tmp->data, b, 0), b, &utils);
	tmp_utils = utils;
	sum = sum_moves(&utils);
	//a->top = a->top->next;

	if(!a->top)
		printf("ops!!1");
	while(i < a->size )
	{
		count_moves(tmp->data, a, &utils);
		count_moves(find_match_number(tmp->data, b, 0), b, &utils);
		sum_rr_rrr(&utils);
		if(sum_moves(&utils) == 1 || sum_moves(&utils) == 0)
		{
			sum = sum_moves(&utils);
			tmp_utils = utils;
			break ; 
		}
		else if(sum_moves(&utils) < sum)
		{
			sum = sum_moves(&utils);
			tmp_utils = utils;
		}
		else
			init_utils(&utils);
		//print_utils(&utils);
		//print_stack(a, b);
		tmp = a->top->next;
		i++;
	}
	//a->top = tmp;
	//print_utils(&tmp_utils);
	return(tmp_utils);
}

int sum_moves(t_utils *utils)
{
	int sum;

	sum = 0;
	if (utils->a_rotate)
		sum += utils->a_rotate;
	if(utils->b_rotate)
		sum += utils->b_rotate;
	if(utils->a_reverse_rotate)
		sum += utils->a_reverse_rotate;
	if(utils->b_reverse_rotate)
		sum += utils->b_reverse_rotate;
	if(utils->rr)
		sum += utils->rr;
	if(utils->rrr)
		sum += utils->rrr;	
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
	else if(stack->charac == 'b')
		utils->b_data = data;
	if(index_node == middle_index || index_node <= middle_index)
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