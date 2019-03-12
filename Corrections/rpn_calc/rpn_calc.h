/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rpn_calc.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishaimou <ishaimou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 16:07:25 by ishaimou          #+#    #+#             */
/*   Updated: 2019/02/20 16:07:26 by ishaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_CALC_H
# define RPN_CALC_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>

typedef struct		s_stack
{
	int				data;
	struct s_stack	*next;
}					t_stack;

void	push(t_stack **stack, int data);
int		pop(t_stack **stack);
int		check_error(char *expr);
int		eval(int nb1, int nb2, char op);
void	rpn_calc(char *expr);
int		is_blank(char c);
int		is_digit(char c);
int		is_number(char *s, int i);
int		is_op(char c);

#endif
