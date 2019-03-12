/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishaimou <ishaimou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 16:07:36 by ishaimou          #+#    #+#             */
/*   Updated: 2019/02/20 16:07:39 by ishaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rpn_calc.h"

int		main(int argc, char *argv[])
{
	if (argc == 2 && check_error(argv[1]))
		rpn_calc(argv[1]);
	else
		printf("Error\n");
	return (0);
}
