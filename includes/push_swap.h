#ifndef PUSH_SWAP_H 
#define PUSH_SWAP_H 

#include <stdio.h>
#include <stdlib.h>

typedef struct s_node 
{
	int data;
	struct s_node *next;
}				t_node;

typedef struct s_stack
{
	struct s_node *head;
	struct s_node *node;
	char c;
}				t_stack;



#endif 