/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_and_replace.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishaimou <ishaimou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/03 10:03:46 by ishaimou          #+#    #+#             */
/*   Updated: 2019/02/03 10:04:06 by ishaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

int		main(int argc, char *argv[])
{
	int		i;

	if (argc == 4)
	{
		if (argv[2][1] || argv[3][1])
		{
			ft_putstr("\n");
			exit(-1);
		}
		i = -1;
		while (argv[1][++i])
			if (argv[1][i] == argv[2][0])
				argv[1][i] = argv[3][0];
		ft_putstr(argv[1]);
	}
	ft_putstr("\n");
	return (0);
}
