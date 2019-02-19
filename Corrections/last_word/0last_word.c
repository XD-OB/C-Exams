/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_word.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishaimou <ishaimou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 04:49:02 by ishaimou          #+#    #+#             */
/*   Updated: 2019/01/27 04:49:04 by ishaimou         ###   ########.fr       */
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
	return (c == 32 || c == 9);
}

int		main(int argc, char *argv[])
{
	int		i;

	if (argc == 2)
	{
		i = 0;
		while (argv[1][i])
			i++;
		i--;	
		while (is_blank(argv[1][i]))
			i--;
		if (i < 0)
		{
			ft_putstr("\n");
			return (0);
		}
		argv[1][i + 1] = '\0';
		while (!is_blank(argv[1][i]) && i >= 0)
			i--;
		i++;
		ft_putstr(&argv[1][i]);
	}
	ft_putstr("\n");
	return (0);
}
