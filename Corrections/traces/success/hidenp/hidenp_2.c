/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hidenp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishaimou <ishaimou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/03 08:57:17 by ishaimou          #+#    #+#             */
/*   Updated: 2019/02/03 08:57:41 by ishaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	hidenp(char *s1, char *s2)
{
	while (*s1)
	{
		while (*s2 && *s1 != *s2)
			s2++;
		if (!*s2)
		{
			write(1, "0", 1);
			return;
		}
		s2++;
		s1++;
	}
	write(1, "1", 1);

}

int		main(int argc, char *argv[])
{
	if (argc == 3)
		hidenp(argv[1], argv[2]);
	write(1, "\n", 1);
	return (0);
} 
