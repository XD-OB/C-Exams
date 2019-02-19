/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_and_replace.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishaimou <ishaimou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 17:01:15 by ishaimou          #+#    #+#             */
/*   Updated: 2019/02/18 17:01:30 by ishaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int		main(int argc, char *argv[])
{
	if (argc == 4 && !argv[2][1] && !argv[3][1])
	{
		while (*argv[1])
		{
			if (*argv[1] == *argv[2])
				*argv[1] = *argv[3];
			write(1, argv[1]++, 1);
		}
	}
	write(1, "\n", 1);
	return (0);
}
