/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_word.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishaimou <ishaimou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 08:18:54 by ishaimou          #+#    #+#             */
/*   Updated: 2019/02/04 08:19:04 by ishaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		is_blank(char c)
{
	return (c == 32 || c == 9);
}

int		main(int argc, char *argv[])
{
	if (argc == 2)
	{
		while (*argv[1])
			argv[1]++;
		argv[1]--;
		while (is_blank(*argv[1]))
			argv[1]--;
		while (*argv[1] && !is_blank(*argv[1]))
			argv[1]--;
		argv[1]++;
		while (*argv[1] && !is_blank(*argv[1]))
			write(1, argv[1]++, 1);
	}
	write(1, "\n", 1);
	return (0);
}
