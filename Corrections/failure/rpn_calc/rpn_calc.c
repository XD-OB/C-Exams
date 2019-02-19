/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rpn_calc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishaimou <ishaimou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 11:34:06 by ishaimou          #+#    #+#             */
/*   Updated: 2019/02/02 11:34:08 by ishaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rpn_calc.h"


void	rpn_calc(char *s)
{
	t_s	**stack;
	int	num1;
	int	num2;

	if (!(stack = (t_s **)malloc(sizeof(t_s*))))
		return ;
	while (*s)
	{
		while (*s && is_space(*s))
			s++;
		if (*s && is_digit(*s))
		{
			push(stack, atoi(s));
			while (*s && is_digit(*s))
				s++;
		}
		else if (*s && is_op(*s))
		{
			if (*(s + 1) && is_digit(*(s + 1)))
			{
				push(stack, atoi(s));
				s++;
				while (is_digit(*s))
					s++;
			}
			else {
				num1 = pop(stack);
				num2 = pop(stack);
				if (num2 == 0 && (*s == '/' || *s == '%'))
				{
					printf("Error\n");
					return ;
				}
				push(stack, do_op(num1, num2, *s));
				s++;
			}
		}
	}
	printf("%i\n", (*stack)->i);
	
}

void	push(t_s **stack, int i)
{
	t_s	*link;

	if (!(link = (t_s *)malloc(sizeof(t_s))))
		return ;
	link->i = i;
	if (*stack)
	{
		link->next = *stack;
		*stack = link;
	}
	else
	{
		link->next = *stack;
		stack = &link;
	}
}

int		pop(t_s **stack)
{
	int	num;
	t_s *tmp;

	num = (*stack)->i;
	tmp = (*stack);
	*stack = (*stack)->next;
	free(tmp);
	return (num);
}

int	do_op(int i, int j, char c)
{
	if (c == '+')
		return (i + j);
	else if (c == '-')
		return (i - j);
	else if (c == '*')
		return (i * j);
	else if (c == '/')
		return (i / j);
	else if (c == '%')
		return (i % j);
	return (0);
}
