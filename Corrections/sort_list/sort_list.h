#include "list.h"

t_list	*sort_list(t_list* lst, int (*cmp)(int, int))
{
	int		size;
	int		tmp;
	t_list	*current;

	if (!lst || !cmp)
		return (0);
	size = 0;
	current = lst;
	while (current)
	{
		current = current->next;
		size++;
	}
	while (--size > 0)
	{
		current = lst;
		while (current->next)
		{
			if (!(*cmp)(current->data, current->next->data))
			{
				tmp = current->data;
				current->data = current->next->data;
				current->next->data = tmp;
			}
			current = cuurent->next;
		}
	}
}
