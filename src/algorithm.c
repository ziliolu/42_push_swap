#include "../includes/push_swap.h"

int execute(t_stack *a, t_stack *b)
{
	t_utils utils;
	int i;

	if(a->size == 2 && (is_organized(*a) == -1))
	{
		swap(a);
		return(1);
	}
	if(a->size == 3)
	{
		sort3(a);
		return (1);
	}
	if(a->size == 5)
	{
		sort5(a, b);
		return (1);
	}
	push(b, new_node(pop(a)), 1);
	push(b, new_node(pop(a)), 1);
	i = a->size;
	while(i > 3 && is_organized(*a) == -1)
	{
		utils = push_swap_init(a, b);
		sum_rr_rrr(&utils);
		run_utils(&utils, a, b);

		push(b, new_node(pop(a)), 1);
		i--;
	}
	sort3(a);
	i = b->size;
	while(i > 0)
	{
		utils = push_swap(b, a);
		sum_rr_rrr(&utils);
		run_utils(&utils, a, b);
		push(a, new_node(pop(b)), 1);
		i--;
	}
	organize_stack_a(init_utils(&utils), a, b);
	return (1);
}

t_utils push_swap(t_stack *origin, t_stack *dest)
{
	t_utils utils;
	t_utils tmp_utils;
	t_stack tmp;

	init_utils(&utils);
	init_utils(&tmp_utils);

	int i;
	static int sum;

	i = 0;
	sum = 0;
	tmp = copy_stack(origin);
	count_moves(tmp.top->data, origin, &utils);
	count_moves(find_perfect_match(tmp.top->data, dest), dest, &utils);
	tmp_utils = utils;
	sum = sum_moves(&utils);

	if(!origin->top)
		printf("ops!!1");
	while(i < origin->size )
	{
		count_moves(tmp.top->data, origin, &utils);
		count_moves(find_perfect_match(tmp.top->data, dest), dest, &utils);
		sum_rr_rrr(&utils);
		if(sum_moves(&utils) == 0)
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
		tmp.top = tmp.top->next; 
		i++;
	}
	free_stack(&tmp);
	return(tmp_utils);
}

void final_organization(t_stack *a, t_stack *b)
{
	t_utils utils;
	while(b->size > 0)
	{
		push_back(a, b);
	}
	organize_stack_a(init_utils(&utils), a, b);
}

void organize_stack_a(t_utils *utils, t_stack *a, t_stack *b)
{
	count_moves(find_lowest_number(a), a, utils);
	run_utils(utils, a, b);
}

void push_back(t_stack *a, t_stack *b)
{
	t_utils utils;
	init_utils(&utils);

	count_moves(find_perfect_match(b->top->data, a), a, &utils);
	run_utils(&utils, a, b);
	push(a, new_node(pop(b)), 1);
}

void sum_rr_rrr(t_utils *utils)
{
	if(utils->a_rotate != 0 && utils->b_rotate != 0)
	{
		if(utils->a_rotate == utils->b_rotate)
		{
			utils->rr = utils->a_rotate;
			utils->a_rotate = 0;
			utils->b_rotate = 0; 
		}
		else
		{
			if(utils->a_rotate > utils->b_rotate)
			{
				utils->rr = utils->a_rotate - (utils->a_rotate - utils->b_rotate);
				utils->a_rotate = utils->a_rotate - utils->b_rotate;
				utils->b_rotate = 0;
			}
			else
			{
				utils->rr = utils->b_rotate - (utils->b_rotate - utils->a_rotate);
				utils->b_rotate = utils->b_rotate - utils->a_rotate;
				utils->a_rotate = 0;
			}
		}
	} else if (utils->a_reverse_rotate != 0 && utils->b_reverse_rotate != 0)
	{
		if(utils->a_reverse_rotate == utils->b_reverse_rotate)
		{
			utils->rrr = utils->a_reverse_rotate;
			utils->a_reverse_rotate = 0;
			utils->b_reverse_rotate = 0; 
		}
		else
		{
			if(utils->a_reverse_rotate > utils->b_reverse_rotate)
			{
				utils->rrr = utils->a_reverse_rotate - (utils->a_reverse_rotate - utils->b_reverse_rotate);
				utils->a_reverse_rotate = utils->a_reverse_rotate - utils->b_reverse_rotate;
				utils->b_reverse_rotate = 0;
			}
			else
			{
				utils->rrr = utils->b_reverse_rotate - (utils->b_reverse_rotate - utils->a_reverse_rotate);
				utils->b_reverse_rotate = utils->b_reverse_rotate - utils->a_reverse_rotate;
				utils->a_reverse_rotate = 0;
			}
		}
	}
}

int is_organized(t_stack stack)
{
	t_node *tmp;
	t_node *head;
	int i = 0;

	head = stack.top;
	while(i < stack.size && stack.top->next != head && stack.top->next)
	{
		tmp = stack.top;
		if(stack.top->next->data < tmp->data)
			return (-1);
		stack.top = stack.top->next;
		i++;
	}
	// free(head);
	// free(tmp);
	return (1);
}
