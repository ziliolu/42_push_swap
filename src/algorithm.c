#include "../includes/push_swap.h"

void execute(t_stack *a, t_stack *b)
{
	t_utils utils;
	int i;

	i = 0;

	printf("initializating.....\n");
	push(b, newNode(pop(a)), 1);
	push(b, newNode(pop(a)), 1);
	print_stack(a, b);
	while(i < a->size && a->size > 3)
	{
		utils = push_swap_init(a, b);
		sum_rr_rrr(&utils);
		run_utils(&utils, a, b);
		push(b, newNode(pop(a)), 1);
		print_stack(a, b);	
		printf("stack a size --> %d\n", a->size);
		i++;
	}
	printf("chamando sort 3");
	sort3(a);
	print_stack(a, b);	
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

void push_back(t_stack *a, t_stack *b)
{
	t_utils utils;
	init_utils(&utils);
	while(b->size > 0)
	{
		count_moves(find_match_number(b->top->data, a), a, &utils);
		run_utils(&utils, a, b);
		push(a, newNode(pop(b)), 1);
	}
}