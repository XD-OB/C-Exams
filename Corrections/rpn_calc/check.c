/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishaimou <ishaimou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 16:07:16 by ishaimou          #+#    #+#             */
/*   Updated: 2019/02/20 16:07:56 by ishaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rpn_calc.h"

int	check_error(char *expr)
{
	int	num_c = 0;
	int	op_c = 0;

	while (*expr)
	{
		if (!(is_op(*expr) || is_digit(*expr) || is_blank(*expr)))
			return (0);
		if (is_op(*expr))
		{
			if (num_c && !is_blank(*(expr - 1)))
					return (0);
			if (!((*expr == '-' || *expr == '+') && is_digit(*(expr + 1))))
				op_c++;
		}
		else if (is_digit(*expr))
		{
			if (!num_c || !is_digit(*(expr - 1)))
				num_c++;
		}
		if (is_blank(*expr) && num_c <= op_c)
			return (0);
		++expr;
	}
	return (num_c - op_c == 1 ? 1 : 0);
}
