#include <stdio.h>
#include <stdlib.h>
#include "list.h"

t_list	*sort_list(t_list *lst, int (*cmp)(int, int));

int		ft_cmp_asc(int a, int b)
{
	return (a <= b ? 1 : 0);
}

int		ft_cmp_desc(int a, int b)
{
	return (a >= b ? 1 : 0);
}

void	push(t_list **head, int data)
{
	t_list	*node;

	if (!(node = (t_list*)malloc(sizeof(t_list))))
		return ;
	node->data = data;
	node->next = *head;
	*head = node;
}

void	print_lst(t_list *head)
{
	while (head)
	{
		printf("%d", head->data);
		printf(" -> ");
		head = head->next;
	}
	printf("NULL\n");
}

int		main(void)
{
	t_list	*lst = NULL;
	
	push(&lst, -290);
	push(&lst, 18);
	push(&lst, 0);
	push(&lst, 5);
	push(&lst, 23);

	print_lst(lst);
	lst = sort_list(lst, ft_cmp_asc);
	printf("\n");
	print_lst(lst);
	return (0);
}
