/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishaimou <ishaimou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 08:27:38 by ishaimou          #+#    #+#             */
/*   Updated: 2019/02/04 08:28:05 by ishaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		is_blank(char c)
{
	return (c == 32 || c == 9);
}

char	*trim_str(char *str)
{
	int		i = 0;

	if (*str)
	{
		while (is_blank(*str))
			str++;
		while (str[i])
			i++;
		i--;
		while (str[i] && is_blank(str[i]))
			i--;
		str[i + 1] = '\0';
	}
	return (str);
}

void	expand_str(char *str)
{
	str = trim_str(str);
	while (*str)
	{
		if (!is_blank(*str))
		{
			while (*str && !is_blank(*str))
				write(1, str++, 1);	
			if (*str)
				write(1, "   ", 3);
		}
		else
			str++;
	}
}

int		main(int argc, char *argv[])
{
	if (argc == 2)
		expand_str(argv[1]);
	write(1, "\n", 1);
	return (0);
}
