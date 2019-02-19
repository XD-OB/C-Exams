/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_capitalizer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishaimou <ishaimou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 09:42:54 by ishaimou          #+#    #+#             */
/*   Updated: 2019/02/08 09:57:40 by ishaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

int		is_blank(char c)
{
	return (c == 9 || c == 32);
}

int		is_lowercase(char c)
{
	return (c < 123 && c > 96);
}

void	ft_str_tolower(char *str)
{
	int		i;
	
	i = 0;
	while (str[i])
	{
		if (str[i] < 91 && str[i] > 64)
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
			ft_str_tolower(argv[i]);
			j = 0;
			while (argv[i][j])
			{
				while(is_blank(argv[i][j]))
					j++;
				if (is_lowercase(argv[i][j]))
					argv[i][j++] -= 32;
				while(argv[i][j] && !is_blank(argv[i][j]))
					j++;
			}
			ft_putstr(argv[i]);
			ft_putstr("\n");
		}
	}
	else
		ft_putstr("\n");
	return (0);
}
