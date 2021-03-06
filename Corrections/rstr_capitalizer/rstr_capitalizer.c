/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rstr_capitalizer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishaimou <ishaimou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 17:41:25 by ishaimou          #+#    #+#             */
/*   Updated: 2019/02/18 17:42:48 by ishaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		is_blank(char c)
{
	return(c == 32 || c == 9);
}

int		is_lowercase(char c)
{
	return (c >= 97 && c <= 122);
}

void	str_tolower(char *str)
{
	int		i = 0;
	while (str[i])
	{
		if (str[i] >= 65 && str[i] <= 90)
			str[i] += 32;
		i++;
	}
}

int		main(int argc, char *argv[])
{
	int		i;
	int		j;

	if (argc > 1)
	{
		i = 0;
		while (++i < argc)
		{
			str_tolower(argv[i]);
			j = 0;
			while (argv[i][j])
			{
				if (is_lowercase(argv[i][j]) && (is_blank(argv[i][j + 1]) || !argv[i][j + 1]))
					argv[i][j] -= 32;
				write(1, &argv[i][j++], 1);
			}
			write(1, "\n", 1);
		}
	}
	else
		write(1, "\n", 1);
	return (0);
}
