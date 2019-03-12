/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishaimou <ishaimou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 11:14:26 by ishaimou          #+#    #+#             */
/*   Updated: 2019/02/02 11:20:46 by ishaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
			current = current->next;
		}
	}
	return (lst);
}
