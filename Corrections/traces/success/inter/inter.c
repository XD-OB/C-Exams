/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishaimou <ishaimou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 10:57:54 by ishaimou          #+#    #+#             */
/*   Updated: 2019/02/04 11:08:44 by ishaimou         ###   ########.fr       */
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
			k = 0;
			while (argv[2][j] && argv[1][i] != argv[2][j])
				j++;
			if (argv[2][j])
			{
				while (k < i && argv[1][k] != argv[1][i])
					k++;
				if (k == i)
				write(1, &argv[1][i], 1);
			}
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
