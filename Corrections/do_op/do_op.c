/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishaimou <ishaimou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 05:58:45 by ishaimou          #+#    #+#             */
/*   Updated: 2019/01/27 05:58:46 by ishaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "do_op.h"

int		do_op(int op1, int op2, char operator)
{
	switch (operator) {
		case '+' :
			return (op1 + op2);
		case '-' :
			return (op1 - op2);
		case '*' :
			return (op1 * op2);
		case '/' :
			return (op1 / op2);
		default :
			return (op1 % op2);
	}
}

int		main(int argc, char *argv[])
{
	int	ret;

	if (argc == 4)
	{
		ret = do_op(atoi(argv[1]), atoi(argv[3]), argv[2][0]);
		printf("%d", ret);
	}
	printf("\n");
	return (0);
}
