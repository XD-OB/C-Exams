/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff_first_param.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishaimou <ishaimou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 03:39:42 by ishaimou          #+#    #+#             */
/*   Updated: 2019/01/29 03:39:44 by ishaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		main(int argc, char **argv)
{
	if (argc != 1)
		while (*argv[1])
			write(1, argv[1]++, 1);
	write(1, "\n", 1);
	return (0);
}
