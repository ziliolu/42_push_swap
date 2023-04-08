#include "../includes/push_swap.h"


int find_highest_number(t_stack *b)
{
	int i;
	int max;

	i = 0;
	max = 0;
	if(!b->top || !b)
		return(0);
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

t_stack copy_stack(t_stack *stack)
{
	t_stack tmp_stack;
	t_stack new_stack;

	int i;

	tmp_stack.size = 0;
	tmp_stack.top = NULL;
	new_stack.size = 0;
	new_stack.top = NULL;

	i = 0;
	while(i < stack->size)
	{
		push(&tmp_stack, new_node(stack->top->data), 0);
		i++;
		stack->top = stack->top->next;
	}
	i = 0;
	while (i < tmp_stack.size)
	{
		push(&new_stack, new_node(tmp_stack.top->data), 0);
		i++;
		tmp_stack.top = tmp_stack.top->next;		
	}
	// dar free da stack temporaria!!!!!
	return(new_stack);
}

t_utils push_swap_init(t_stack *a, t_stack *b)
{
	t_utils utils;
	t_utils tmp_utils;
	t_stack a_tmp;

	init_utils(&utils);
	init_utils(&tmp_utils);
	(void)a;

	int i;
	static int sum;
	//t_node *tmp;

	// if(!a || !a->top)
	// 	return (0);
	i = 0;
	sum = 0;
	//tmp = a->top;
	a_tmp = copy_stack(a);
	//print_stack(a, &a_tmp);
	count_moves(a_tmp.top->data, a, &utils);
	count_moves(find_match_number(a_tmp.top->data, b, 0), b, &utils);
	tmp_utils = utils;
	sum = sum_moves(&utils);
	//a->top = a->top->next;

	if(!a->top)
		printf("ops!!1");
	while(i < a_tmp.size )
	{
		//printf("top tmp: %d\n", a_tmp.top->data);
		//printf("top a: %d\n", a->top->data);
		count_moves(a_tmp.top->data, a, &utils);
		count_moves(find_match_number(a_tmp.top->data, b, 0), b, &utils);
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
		a_tmp.top = a_tmp.top->next;
		//printf("tmp do primeiro: %d\n", tmp->data);
		i++;
	}
	//a->top = tmp;
	//print_utils(&tmp_utils);
	free_stack(&a_tmp);
	return(tmp_utils);
}

int sum_moves(t_utils *u)
{
	int sum;

	sum = 0;
	if (u->a_rotate)
		sum += u->a_rotate;
	if(u->b_rotate)
		sum += u->b_rotate;
	if(u->a_reverse_rotate)
		sum += u->a_reverse_rotate;
	if(u->b_reverse_rotate)
		sum += u->b_reverse_rotate;
	if(u->rr)
		sum += u->rr;
	if(u->rrr)
		sum += u->rrr;	
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