/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rpn_calc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishaimou <ishaimou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 16:06:51 by ishaimou          #+#    #+#             */
/*   Updated: 2019/02/20 16:08:12 by ishaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rpn_calc.h"

int		is_blank(char c)
{
	return (c == 32 || c == 9);
}

int		is_digit(char c)
{
	return (c >= 48 && c <= 57);
}

int		is_number(char *s, int i)
{
	return (is_digit(s[i]) || ((s[i] == '-' || s[i] == '+') && is_digit(s[i + 1])));
}

int		is_op(char c)
{
	return (c == '+' ||
			c == '-' ||
			c == '*' ||
			c == '/' ||
			c == '%'
			);
}

int		eval(int nb1, int nb2, char op)
{
	switch (op) {
		case '+' :
			return (nb1 + nb2);
		case '-' :
			return (nb1 - nb2);
		case '*' :
			return (nb1 * nb2);
		case '/' :
			return (nb1 / nb2);
		default:
			return (nb1 % nb2);
	}
}

void	push(t_stack **stack, int data)
{
	t_stack		*node;

	node = (t_stack*)malloc(sizeof(t_stack));
	node->data = data;
	node->next = *stack;
	*stack = node;
}

int		pop(t_stack **stack)
{
	int			ret = -1;
	t_stack		*tmp;

	if (!*stack)
		return (INT_MIN);
	tmp = *stack;
	ret = (*stack)->data;
	*stack = (*stack)->next;
	free(tmp);
	return (ret);
}

void	rpn_calc(char *expr)
{
	t_stack		*stack = NULL;
	int			i = 0;
	int			nb1 = 0;
	int			nb2 = 0;
	int			result = 0;

	while (expr[i])
	{
		while (is_blank(expr[i]))
			i++;
		if (expr[i] && is_number(expr, i)) {
			 push(&stack, atoi(&expr[i]));
		while (expr[i] && is_number(expr, i))
				i++;
		}
		if (expr[i] && is_op(expr[i]) && !is_digit(expr[i + 1]))
		{
			nb2 = pop(&stack);
			nb1 = pop(&stack);
			if (nb2 == 0 && (expr[i] == '/' || expr[i] == '%'))
			{	
				printf("Error\n");
				return ;
			}
			result = eval(nb1, nb2, expr[i]);
			push(&stack, result);
		}
		i++;
	}
	printf("%d\n", pop(&stack));
}
