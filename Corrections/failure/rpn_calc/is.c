/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishaimou <ishaimou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 11:33:42 by ishaimou          #+#    #+#             */
/*   Updated: 2019/02/02 11:33:44 by ishaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rpn_calc.h"

int	is_op(int c)
{
	return (c == '+' ||
			c == '-' ||
			c == '*' ||
			c == '/' ||
			c == '%');
}

int	is_digit(int c)
{
	return ('0' <= c && c <= '9');
}

int	is_space(int c)
{
	return (c == 32);
}