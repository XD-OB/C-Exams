/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brackets.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <obelouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 04:01:27 by obelouch          #+#    #+#             */
/*   Updated: 2019/03/29 05:13:34 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int			closni(char *str, char c)
{
	int		loop = 1;
	int		distance = 1;

	while (loop && *str)
	{
		if (*str == c)
			loop++;
		if (*str == c + c % 2 + 1)
			loop--;
		distance++;
		str++;
	}
	return (distance);
}

int			brackets(char *str, char c)
{
	if (*str == c)
		return (1);
	else if (!*str || *str == ')' || *str == '}' || *str == ']')
		return (0);
	else if (*str == '{' || *str == '(' || *str == "[")
		return (
				brackets(str + 1, *str + *str % 2 + 1)
				* brackets(str + closni(str + 1, *str), c)
				);
	else
		return (brackets(str + 1, c));
}

int			main(int ac, char **av)
{
	int		i = 0;

	if (ac > 1)
		while (++i < ac)
			brackets(av[i], 0) ? write(1, "OK\n", 3) : write(1, "Error\n", 6);
	else
		write(1, "\n", 1);
	return (0);
}
