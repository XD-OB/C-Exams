/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishaimou <ishaimou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 10:50:30 by ishaimou          #+#    #+#             */
/*   Updated: 2019/02/07 10:50:59 by ishaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		main(int argc, char *argv[])
{
	int		i;
	int		j;
	int		k;

	if (argc == 3)
	{
		i = 0;
		while (argv[1][i])
		{
			j = 0;
			while (j < i && argv[1][i] != argv[1][j])
				j++;
			if (j == i)
				write(1, &argv[1][i], 1);
			i++;
		}
		i = 0;
		while (argv[2][i])
		{	
			j = 0;
			while (argv[1][j] && argv[2][i] != argv[1][j])
				j++;
			k = 0;
			while (k < i && argv[2][i] != argv[2][k])
				k++;
			if (!argv[1][j] && k == i)
				write(1, &argv[2][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}  
