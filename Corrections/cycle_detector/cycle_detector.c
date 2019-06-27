/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycle_detector.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <obelouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 17:58:32 by ishaimou          #+#    #+#             */
/*   Updated: 2019/02/18 17:59:33 by ishaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "list.h"

int		cycle_detector(const t_list *list)
{
	t_list	*fast;
	t_list	*slow;
	
	if (!list)
		return (0);
	fast = list->next;
	slow = (t_list*)list;
	while (fast && fast->next && slow)
	{
		if (fast == slow)
			return (1);
		fast = fast->next->next;
		slow = slow->next;
	}
	return (0);
}
