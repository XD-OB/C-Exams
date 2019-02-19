/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishaimou <ilyass.sh@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/24 22:46:55 by ishaimou          #+#    #+#             */
/*   Updated: 2018/12/24 23:16:12 by ishaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "do_op.h"


int		do_op(int op1, int op2, char operator)
{
	if (operator == '+')
		return (op1 + op2);
	if (operator == '-')
		return (op1 - op2);
	if (operator == '*')
		return (op1 * op2);
	if (operator == '/')
		return (op1 / op2);
	return (op1 % op2);
}

int		main(int argc, char **argv)
{
	int		res;

	if (argc == 4)
	{
		res = do_op(atoi(argv[1]), atoi(argv[3]), argv[2][0]);
		printf("%d", res);
	}
	printf("\n");	
	return (0);
}
