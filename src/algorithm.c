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
	push(b, newNode(pop(a)), 1);
	push(b, newNode(pop(a)), 1);
	i = a->size;
	while(i > 3 && is_organized(*a) == -1)
	{
		utils = push_swap_init(a, b);
		sum_rr_rrr(&utils);
		run_utils(&utils, a, b);
		push(b, newNode(pop(a)), 1);
		i--;
	}
	sort3(a);
	i = b->size;
	// while(i > 0)
	// {
	// 	utils = push_swap(b, a);
	// 	sum_rr_rrr(&utils);
	// 	run_utils(&utils, a, b);
	// 	push(a, newNode(pop(b)), 1);
	// 	i--;
	// }
	//organize_stack_a(init_utils(&utils), a, b);
	return (1);
}

t_utils push_swap(t_stack *origin, t_stack *dest)
{
	t_utils utils;
	t_utils tmp_utils;

	init_utils(&utils);
	init_utils(&tmp_utils);

	int i;
	static int sum;
	t_node *tmp;

	// if(!a || !a->top)
	// 	return (0);
	i = 0;
	sum = 0;
	tmp = origin->top;
	count_moves(tmp->data, origin, &utils);
	count_moves(find_perfect_match(tmp->data, dest), dest, &utils);
	tmp_utils = utils;
	sum = sum_moves(&utils);

	if(!origin->top)
		printf("ops!!1");
	while(i < origin->size )
	{
		count_moves(tmp->data, origin, &utils);
		count_moves(find_perfect_match(tmp->data, dest), dest, &utils);
		sum_rr_rrr(&utils);
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
		tmp = origin->top->next;
		i++;
	}
	return(tmp_utils);
}

void final_organization(t_stack *a, t_stack *b)
{
	t_utils utils;
	while(b-> size > 0)
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
	push(a, newNode(pop(b)), 1);
}

void run_utils(t_utils *u, t_stack *a, t_stack *b)
{
	while(u->a_rotate != 0 || u->b_rotate != 0 || u->a_reverse_rotate != 0 || u->b_reverse_rotate != 0)
		{
			if(u->a_rotate > 0)
			{
				rotate(a, 1);
				u->a_rotate--;
			}
			if(u->b_rotate > 0)
			{
				rotate(b, 1);
				u->b_rotate--;
			}
			if(u->a_reverse_rotate > 0)
			{
				reverse_rotate(a, 1);
				u->a_reverse_rotate--;
			}
			if(u->b_reverse_rotate > 0)
			{
				reverse_rotate(b, 1);
				u->b_reverse_rotate--;
			}
			if(u->rr > 0)
			{
				rr(a, b);
				u->rr--;
			}
			if(u->rrr > 0)
			{
				rr(a, b);
				u->rrr--;
			}
		}
	
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
	while(i < stack.size && stack.top->next != head)
	{
		tmp = stack.top;
		if(stack.top->next->data < tmp->data)
			return (-1);
		stack.top = stack.top->next;
		i++;
	}
	return (1);
}
