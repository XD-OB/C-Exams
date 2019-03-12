/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brainfuck.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frodrigu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 06:10:21 by frodrigu          #+#    #+#             */
/*   Updated: 2018/02/01 07:25:23 by frodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_brainfuck(char *str)
{
	int		i;
	char	*ptr;

	i = 0;
	ptr = (char*)malloc(sizeof(ptr) * 2048);
	while (str[i] != '\0')
	{
		*ptr += str[i] == '+' ? 1 : 0;
		*ptr -= str[i] == '-' ? 1 : 0;
		ptr += str[i] == '>' ? 1 : 0;
		ptr -= str[i] == '<' ? 1 : 0;
		if (str[i] == '[' && *ptr == 0)
			while (str[i] != ']')
				i++;
		if (str[i] == ']' && *ptr != 0)
			while (str[i] != '[')
				i--;
		if (str[i] == '.')
			write(1, ptr, 1);
		i++;
	}
}

int		main(int argc, char **argv)
{
	(argc == 2 && argv[1][0]) ? ft_brainfuck(argv[1]) : ft_putchar('\n');
}
