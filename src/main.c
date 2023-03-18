#include "../includes/push_swap.h"

t_node *newNode(int data)
{
	t_node *node;
	node = malloc(sizeof(node));
	node->data = data;
	node->next = NULL;
	return (node);
}

// int main(int argc, char *argv)
// {
// 	verify_arguments();
// 	t_stack a; 

// 	a.head = newNode(10);
// 	a.head->next = newNode(15);
// 	a.node = a.head;
// 	while(a.node)
// 	{
// 		printf("%d\n", a.node->data);
// 		a.node = a.node->next;
// 	}
// 	printf("head: %d\n", a.head->data);

// }

int is_number(char c)
{
	if(c >= '0' && c <= '9')
		return (1);
	return (-1);
}

int read_args(int argc, char **argv)
{
	int i;
	int j;


	
}

int main(int argc, char **argv)
{
	if(read_args(argc, argv) == 1)
		printf("argumentos validos!");
	else
	{
		printf("invalido");
	}
}