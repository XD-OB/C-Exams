/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishaimou <ishaimou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/03 11:36:07 by ishaimou          #+#    #+#             */
/*   Updated: 2019/02/03 11:37:09 by ishaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		is_alpha(char c)
{
	return ((c < 91 && c > 64) || (c < 123 && c > 96));
}

int	alpha_pos(char c)
{
	return (!is_alpha(c) ? 1 : c < 91 && c > 64 ? c - 64 : c - 96);
}

int		main(int argc, char *argv[])
{
	int	pos;

	if (argc == 2)
	{
		while (*argv[1])
		{
			pos = alpha_pos(*argv[1]);
				while (pos--)
					write(1, argv[1], 1);
			argv[1]++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
